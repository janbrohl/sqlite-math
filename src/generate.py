import string
import pathlib

here = pathlib.Path(__file__).parent

header = """
/* Add your header comment here */
#include <math.h>
#include <sqlite3ext.h> /* Do not use <sqlite3.h>! */
SQLITE_EXTENSION_INIT1


/* Get exponent */
static int frexp_exponent(double x)
{
    int exponent;
    frexp(x, &exponent);
    return exponent;
}

/* Get significand */
static double frexp_significand(double x)
{
    int exponent;
    return frexp(x, &exponent);
}

/* Break into fractional and integral parts -> integral */
static double modf_integral(double x)
{
    double integral;
    modf(x, &integral);
    return integral ;
}

/* Break into fractional and integral parts -> fractional  */
static double modf_fractional(double x)
{
    double integral;
    return modf(x, &integral);
}

/* Compute quotient */
static double remquo_quotient(double numer, double denom)
{
    double quot;
    remquo(numer, denom, &quot);
    return quot;
}

/* Compute remainder */
static double remquo_remainder(double numer, double denom)
{
    return remainder(numer, denom);
}

"""

func1_template = string.Template("""
/* ${desc} */
static void ${name}Func(sqlite3_context *context, int argc, sqlite3_value **argv)
{

  assert(argc == 1);
  double arg;
  
    int t = sqlite3_value_type(argv[0]);
    if (t == SQLITE_FLOAT || t == SQLITE_INTEGER)
    {
      arg = sqlite3_value_double(argv[0]);
    }
    else
    {
      sqlite3_result_null(context);
      return;
    }
  
  sqlite3_result_double(context, ${name}(arg));
  return;
}
""")

func2_template = string.Template("""
/* ${desc} */
static void ${name}Func(sqlite3_context *context, int argc, sqlite3_value **argv)
{

  assert(argc == 2);
  double args[2];
  for (int i = 0; i < 2; i++)
  {
    int t = sqlite3_value_type(argv[i]);
    if (t == SQLITE_FLOAT || t == SQLITE_INTEGER)
    {
      args[i] = sqlite3_value_double(argv[i]);
    }
    else
    {
      sqlite3_result_null(context);
      return;
    }
  }
  sqlite3_result_double(context, ${name}(args[0], args[1]));
  return;
}
""")

func3_template = string.Template("""
/* ${desc} */
static void ${name}Func(sqlite3_context *context, int argc, sqlite3_value **argv)
{

  assert(argc == 3);
  double args[3];
  for (int i = 0; i < 3; i++)
  {
    int t = sqlite3_value_type(argv[i]);
    if (t == SQLITE_FLOAT || t == SQLITE_INTEGER)
    {
      args[i] = sqlite3_value_double(argv[i]);
    }
    else
    {
      sqlite3_result_null(context);
      return;
    }
  }
  sqlite3_result_double(context, ${name}(args[0], args[1], args[2]));
  return;
}
""")

init_template = string.Template("""
int sqlite3_${name}_init(
    sqlite3 *db,
    char **pzErrMsg,
    const sqlite3_api_routines *pApi)
{
  int rc = SQLITE_OK;
  SQLITE_EXTENSION_INIT2(pApi);
  
""")

func_create_template = string.Template("""
  rc = sqlite3_create_function(db, "${name}", ${num_args},
                               SQLITE_UTF8 | SQLITE_DETERMINISTIC,
                               NULL, ${name}Func, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}""")

footer = """
  return rc;
}
"""

with open(here / 'func1.txt', 'rt', encoding='ascii') as f:
    func1 = {
        name: desc
        for name, _0, desc in (line.strip().partition(':') for line in f
                               if line.strip())
    }
with open(here / 'func2.txt', 'rt', encoding='ascii') as f:
    func2 = {
        name: desc
        for name, _0, desc in (line.strip().partition(':') for line in f
                               if line.strip())
    }
with open(here / 'func3.txt', 'rt', encoding='ascii') as f:
    func3 = {
        name: desc
        for name, _0, desc in (line.strip().partition(':') for line in f
                               if line.strip())
    }

with open(here / 'potentially-builtin-functions.txt', 'rt',
          encoding='ascii') as f:
    pbif = [
        name for name, _0, _1 in (line.strip().partition('(') for line in f
                                  if line.strip())
    ]

with open(here.parent / 'math1.c', 'wt', encoding='ascii') as f:
    f.write(header)
    for name, desc in func1.items():
        f.write(func1_template.substitute(name=name, desc=desc))
    for name, desc in func2.items():
        f.write(func2_template.substitute(name=name, desc=desc))
    for name, desc in func3.items():
        f.write(func3_template.substitute(name=name, desc=desc))
    f.write(init_template.substitute(name='math1'))
    for name, desc in func1.items():
        f.write(func_create_template.substitute(name=name, num_args=1))
    for name, desc in func2.items():
        f.write(func_create_template.substitute(name=name, num_args=2))
    for name, desc in func3.items():
        f.write(func_create_template.substitute(name=name, num_args=3))
    f.write(footer)

with open(here.parent / 'mathextra1.c', 'wt', encoding='ascii') as f:
    f.write(header)
    for name, desc in func1.items():
        if name not in pbif:
            f.write(func1_template.substitute(name=name, desc=desc))
    for name, desc in func2.items():
        if name not in pbif:
            f.write(func2_template.substitute(name=name, desc=desc))
    for name, desc in func3.items():
        if name not in pbif:
            f.write(func3_template.substitute(name=name, desc=desc))
    f.write(init_template.substitute(name='mathextra1'))
    for name, desc in func1.items():
        if name not in pbif:
            f.write(func_create_template.substitute(name=name, num_args=1))
    for name, desc in func2.items():
        if name not in pbif:
            f.write(func_create_template.substitute(name=name, num_args=2))
    for name, desc in func3.items():
        if name not in pbif:
            f.write(func_create_template.substitute(name=name, num_args=3))
    f.write(footer)
