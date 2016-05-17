bool FileExists(std::string fname)
{
	const char *filename = fname.c_str();
  return _access(filename, 0) != -1;
}