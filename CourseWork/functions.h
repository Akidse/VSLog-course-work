bool FileExists(std::string fname)
{
	const char *filename = fname.c_str();
  return _access(filename, 0) != -1;
}

void cut_str(std::string &str, std::string &buf, int from, int to)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(i >= from && i <= to)
		{
			buf.push_back(str[i]);
		}
	}
}