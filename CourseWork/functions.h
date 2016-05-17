bool FileExists(const char *fname)
{
  return _access(fname, 0) != -1;
}