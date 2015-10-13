#include "stdafx.h"
#include "EML.h"


EML::EML()
{
}


EML::~EML()
{
}

void EML::출발()
{
	setlocale(LC_ALL, "korean");
	CStdioFile rfile, wfile;
	CString data_str;
	std::regex pattern("\\w*\t([0-9]{4})""/([0-9]{2})""/([0-9]{2})"" ([0-9]{2})"":([0-9]{2})"":([0-9]{2})""\t([\\w]*):""[a-zA-Z0-9\\s]*\\[[a-zA-Z0-9\\s]*\\][a-zA-Z0-9\\s]*\\[(\\S*)\\]"" ([a-zA-Z0-9\\s\\[\\]\\.]*)");
	std::string replacer = "$7,$8,$1³â $2¿ù $3ÀÏ $4½Ã $5ºÐ $6ÃÊ,$9\n";
	if (rfile.Open(_T("test.eml"), CFile::modeRead | CFile::typeText))
	{
		wfile.Open((CString)"Q_1.csv", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
		while (rfile.ReadString(data_str))
		{
			CT2CA pszConvertedAnsiString(data_str);
			wfile.WriteString((CString)std::regex_replace((std::string)pszConvertedAnsiString, pattern, replacer).c_str());
		}
		rfile.Close();
		wfile.Close();
	}
	else
	{
		MessageBoxW(0, _T("test.eml이 없어요"), 0, 0);
	}
}