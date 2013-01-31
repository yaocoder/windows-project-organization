
#include "gtest/gtest.h"
#include "../../src/TinyXmlWrapper/tinyxml_wrapper.h"
#include "../../src/utils/path_utils.h"
#include <string>

//gtest filter: --gtest_filter=TinyXmlWrapperTest.TestGetElementText

TEST(TinyXmlWrapperTest, TestGetElementText)
{
	XmlOperate::CTinyXmlWrapper tiny_xml_obj;
	std::string test_file_path = path_utils::GetAppDirectory() + "\\test.xml";
	ASSERT_TRUE(tiny_xml_obj.LoadXmlDocument(test_file_path));
	ASSERT_EQ("Welcome to MyAp", tiny_xml_obj.GetElementText("MyApp&Messages&Welcome"));
}

TEST(TinyXmlWrapperTest, TestGetElementAttribute)
{
	XmlOperate::CTinyXmlWrapper tiny_xml_obj;
	std::string test_file_path = path_utils::GetAppDirectory() + "\\test.xml";
	ASSERT_TRUE(tiny_xml_obj.LoadXmlDocument(test_file_path));
	ASSERT_EQ("MainFram", tiny_xml_obj.GetElementAttribute("MyApp&Windows&Window", "name"));
}
