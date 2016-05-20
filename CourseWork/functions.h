bool FileExists(std::string fname)
{
	const char *filename = fname.c_str();
  return _access(filename, 0) != -1;
}

void list(std::string path, bool only_folder)
{
	int k = 0;
	std::wstring stemp = std::wstring(path.begin(), path.end());
    LPCWSTR sw = stemp.c_str();
	WIN32_FIND_DATAW wfd;
    HANDLE const hFind = FindFirstFileW(sw, &wfd);
    if (INVALID_HANDLE_VALUE != hFind)
    {
      do
      {
		  if(only_folder && k >1)
		  {
            if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && only_folder)std::wcout  << &wfd.cFileName[0]  << std::endl;
			
		  }
		  k++;
      } while (NULL != FindNextFileW(hFind, &wfd));
 
      FindClose(hFind);
    }
}

int count_line_file(std::string file)
{
    char *str = new char [1024];
    int i = 0;
    std::ifstream base(file);
    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }
    base.close();
    delete str;
	return i;
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