// TinyXmlWrapper.cpp : 定义控制台应用程序的入口点。
//

#include <tchar.h>
#include "tinyxml_wrapper.h"
#include "../src/utils/path_utils.h"
#include <iostream>
#include <Shlwapi.h>
#include <log4cxx/logger.h>
#include <log4cxx/logstring.h>
#include <log4cxx/propertyconfigurator.h>
using namespace log4cxx;
using namespace std;

LoggerPtr g_logger;

void LoadLogConfig()
{
	//加载log4c配置  
	TCHAR szPath[MAX_PATH] = {0};
	GetModuleFileName(NULL,szPath,MAX_PATH - 1);
	PathRemoveFileSpec(szPath);
	lstrcat(szPath,TEXT("\\config\\log.conf"));	
	log4cxx::PropertyConfigurator::configure(szPath);
	g_logger = log4cxx::Logger::getLogger("xml_operate");

}

int _tmain(int argc, _TCHAR* argv[])
{
	LoadLogConfig();
	LOG4CXX_INFO(g_logger, "Start Run Test!");

	std::string current_path		= path_utils::GetAppDirectory();
	std::string current_file_path	= current_path + "\\web.config";
	LOG4CXX_INFO(g_logger, " current_file_path = " << current_file_path);

	XmlOperate::CTinyXmlWrapper tinyxml_wrapper_object;
	if(!tinyxml_wrapper_object.LoadXmlDocument(current_file_path))
		return -1;

	tinyxml_wrapper_object.PrintXml();

	std::string element_path = "configuration&connectionStrings&add";
	std::string testA = tinyxml_wrapper_object.GetElementAttribute(element_path, "providerName");
	std::string test = tinyxml_wrapper_object.GetElementText(element_path);
	cout << test <<endl;

	tinyxml_wrapper_object.SetElementText(element_path, "i am a boy");
		tinyxml_wrapper_object.SetElementAttribute(element_path, "connectionString", "678.00000");
	tinyxml_wrapper_object.SaveXmlDocument();

	system("pause");

	return 0;
}

