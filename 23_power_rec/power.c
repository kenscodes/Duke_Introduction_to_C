unsigned power(unsigned x,unsigned y)
{ if (x==0 && y==0)
    return 1;
  if (y== 0)
    return 1;
  // calculate sub-problem recursively
  int pow = power(x, y / 2);

  if (y & 1) // if y is odd
    return x * pow * pow;

  // else y is even
  return pow * pow;
}
