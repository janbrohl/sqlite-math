
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


/* Compute cosine */
static void cosFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, cos(arg));
  return;
}

/* Compute sine */
static void sinFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, sin(arg));
  return;
}

/* Compute tangent */
static void tanFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, tan(arg));
  return;
}

/* Compute arc cosine */
static void acosFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, acos(arg));
  return;
}

/* Compute arc sine */
static void asinFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, asin(arg));
  return;
}

/* Compute arc tangent */
static void atanFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, atan(arg));
  return;
}

/* Compute hyperbolic cosine */
static void coshFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, cosh(arg));
  return;
}

/* Compute hyperbolic sine */
static void sinhFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, sinh(arg));
  return;
}

/* Compute hyperbolic tangent */
static void tanhFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, tanh(arg));
  return;
}

/* Compute area hyperbolic cosine */
static void acoshFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, acosh(arg));
  return;
}

/* Compute area hyperbolic sine */
static void asinhFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, asinh(arg));
  return;
}

/* Compute area hyperbolic tangent */
static void atanhFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, atanh(arg));
  return;
}

/* Compute exponential function */
static void expFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, exp(arg));
  return;
}

/* Compute natural logarithm */
static void logFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, log(arg));
  return;
}

/* Compute common logarithm */
static void log10Func(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, log10(arg));
  return;
}

/* Compute binary exponential function */
static void exp2Func(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, exp2(arg));
  return;
}

/* Compute exponential minus one */
static void expm1Func(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, expm1(arg));
  return;
}

/* Integer binary logarithm */
static void ilogbFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, ilogb(arg));
  return;
}

/* Compute logarithm plus one */
static void log1pFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, log1p(arg));
  return;
}

/* Compute binary logarithm */
static void log2Func(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, log2(arg));
  return;
}

/* Compute floating-point base logarithm */
static void logbFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, logb(arg));
  return;
}

/* Compute square root */
static void sqrtFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, sqrt(arg));
  return;
}

/* Compute cubic root */
static void cbrtFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, cbrt(arg));
  return;
}

/* Compute error function */
static void erfFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, erf(arg));
  return;
}

/* Compute complementary error function */
static void erfcFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, erfc(arg));
  return;
}

/* Compute gamma function */
static void tgammaFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, tgamma(arg));
  return;
}

/* Compute log-gamma function */
static void lgammaFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, lgamma(arg));
  return;
}

/* Round up value */
static void ceilFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, ceil(arg));
  return;
}

/* Round down value */
static void floorFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, floor(arg));
  return;
}

/* Truncate value */
static void truncFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, trunc(arg));
  return;
}

/* Round to nearest and cast to long integer */
static void lroundFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, lround(arg));
  return;
}

/* Round to nearest and cast to long long integer */
static void llroundFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, llround(arg));
  return;
}

/* Round to integral value */
static void rintFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, rint(arg));
  return;
}

/* Round and cast to long integer */
static void lrintFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, lrint(arg));
  return;
}

/* Round and cast to long long integer */
static void llrintFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, llrint(arg));
  return;
}

/* Round to nearby integral value */
static void nearbyintFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, nearbyint(arg));
  return;
}

/* Compute absolute value */
static void fabsFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, fabs(arg));
  return;
}

/* Get exponent */
static void frexp_exponentFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, frexp_exponent(arg));
  return;
}

/* Get significand */
static void frexp_significandFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, frexp_significand(arg));
  return;
}

/* Break into fractional and integral parts -> integral */
static void modf_integralFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, modf_integral(arg));
  return;
}

/* Break into fractional and integral parts -> fractional */
static void modf_fractionalFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  
  sqlite3_result_double(context, modf_fractional(arg));
  return;
}

/* Compute arc tangent with two parameters */
static void atan2Func(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, atan2(args[0], args[1]));
  return;
}

/* Generate value from significand and exponent */
static void ldexpFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, ldexp(args[0], args[1]));
  return;
}

/* Scale significand using floating-point base exponent */
static void scalbnFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, scalbn(args[0], args[1]));
  return;
}

/* Scale significand using floating-point base exponent */
static void scalblnFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, scalbln(args[0], args[1]));
  return;
}

/* Raise to power */
static void powFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, pow(args[0], args[1]));
  return;
}

/* Compute hypotenuse */
static void hypotFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, hypot(args[0], args[1]));
  return;
}

/* Compute remainder of division */
static void fmodFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, fmod(args[0], args[1]));
  return;
}

/* Compute remainder */
static void remainderFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, remainder(args[0], args[1]));
  return;
}

/* Copy sign */
static void copysignFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, copysign(args[0], args[1]));
  return;
}

/* Next representable value */
static void nextafterFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, nextafter(args[0], args[1]));
  return;
}

/* Next representable value toward precise value */
static void nexttowardFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, nexttoward(args[0], args[1]));
  return;
}

/* Positive difference */
static void fdimFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, fdim(args[0], args[1]));
  return;
}

/* Maximum value */
static void fmaxFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, fmax(args[0], args[1]));
  return;
}

/* Minimum value */
static void fminFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, fmin(args[0], args[1]));
  return;
}

/* Compute quotient */
static void remquo_quotientFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, remquo_quotient(args[0], args[1]));
  return;
}

/* Compute remainder */
static void remquo_remainderFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, remquo_remainder(args[0], args[1]));
  return;
}

/* Multiply-add */
static void fmaFunc(sqlite3_context *context, int argc, sqlite3_value **argv)
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
  sqlite3_result_double(context, fma(args[0], args[1], args[2]));
  return;
}

int sqlite3_math1_init(
    sqlite3 *db,
    char **pzErrMsg,
    const sqlite3_api_routines *pApi)
{
  int rc = SQLITE_OK;
  SQLITE_EXTENSION_INIT2(pApi);
  

  rc = sqlite3_create_function(db, "cos", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, cosFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "sin", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, sinFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "tan", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, tanFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "acos", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, acosFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "asin", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, asinFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "atan", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, atanFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "cosh", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, coshFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "sinh", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, sinhFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "tanh", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, tanhFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "acosh", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, acoshFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "asinh", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, asinhFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "atanh", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, atanhFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "exp", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, expFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "log", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, logFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "log10", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, log10Func, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "exp2", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, exp2Func, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "expm1", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, expm1Func, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "ilogb", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, ilogbFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "log1p", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, log1pFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "log2", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, log2Func, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "logb", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, logbFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "sqrt", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, sqrtFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "cbrt", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, cbrtFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "erf", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, erfFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "erfc", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, erfcFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "tgamma", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, tgammaFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "lgamma", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, lgammaFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "ceil", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, ceilFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "floor", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, floorFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "trunc", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, truncFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "lround", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, lroundFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "llround", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, llroundFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "rint", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, rintFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "lrint", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, lrintFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "llrint", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, llrintFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "nearbyint", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, nearbyintFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "fabs", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, fabsFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "frexp_exponent", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, frexp_exponentFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "frexp_significand", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, frexp_significandFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "modf_integral", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, modf_integralFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "modf_fractional", 1,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, modf_fractionalFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "atan2", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, atan2Func, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "ldexp", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, ldexpFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "scalbn", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, scalbnFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "scalbln", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, scalblnFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "pow", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, powFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "hypot", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, hypotFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "fmod", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, fmodFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "remainder", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, remainderFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "copysign", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, copysignFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "nextafter", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, nextafterFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "nexttoward", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, nexttowardFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "fdim", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, fdimFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "fmax", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, fmaxFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "fmin", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, fminFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "remquo_quotient", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, remquo_quotientFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "remquo_remainder", 2,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, remquo_remainderFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  rc = sqlite3_create_function(db, "fma", 3,
                               SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC,
                               NULL, fmaFunc, NULL, NULL);
  if(rc!=SQLITE_OK ){
    return rc;
}
  return rc;
}
