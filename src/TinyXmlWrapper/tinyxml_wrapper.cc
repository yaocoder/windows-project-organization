
#include "tinyxml_wrapper.h"
#include "../src/utils/utils.h"
#include <vector>

#define SPLIT_FLAG "&"

namespace XmlOperate
{
	CTinyXmlWrapper::CTinyXmlWrapper(void)
		:ptr_doc_(new TiXmlDocument())
	{
	}

	CTinyXmlWrapper::~CTinyXmlWrapper(void)
	{
		Destory();
	}

	bool CTinyXmlWrapper::LoadXmlDocument( const std::string& file_name)
	{
		return ptr_doc_->LoadFile(file_name); 
	}

	bool CTinyXmlWrapper::SaveXmlDocument()
	{
		return ptr_doc_->SaveFile();
	}

	TiXmlElement* CTinyXmlWrapper::FindElementByElemPath( const std::string& element_path)
	{
		TiXmlHandle doc_handle_object(ptr_doc_);

		std::vector<std::string> vec_child;
		utils::MySplitString(element_path, SPLIT_FLAG, vec_child);

		std::vector<std::string>::iterator iter = vec_child.begin();
		TiXmlNode* ptr_node = NULL;
		TiXmlHandle xml_handle(ptr_node);
		xml_handle = doc_handle_object.FirstChild(*iter);	
		for (iter++; iter != vec_child.end(); ++iter)
		{
			xml_handle = xml_handle.FirstChild(*iter);	
		}

		return  xml_handle.ToElement();
	}

	std::string CTinyXmlWrapper::GetElementText(const std::string& element_path )
	{
		TiXmlElement *ptr_element = FindElementByElemPath(element_path);	
		if (NULL == ptr_element)
			return std::string("");

		
		const char *ch_text = ptr_element->GetText();
		if (ch_text)
			return std::string(ch_text);
		else
			return std::string("");;

	}

	bool CTinyXmlWrapper::SetElementText( const std::string& element_path, 
										  const std::string& new_text )
	{
		TiXmlElement* ptr_element = FindElementByElemPath(element_path);
		if (NULL == ptr_element)
			return false;

		TiXmlNode* node_ptr = ptr_element->FirstChild();
		TiXmlText text_object(new_text);
		ptr_element->ReplaceChild(node_ptr, text_object);

		return true;
	}


	std::string CTinyXmlWrapper::GetElementAttribute( const std::string& element_path, 
													  const std::string& attribute_name )
	{
		TiXmlElement *ptr_element = FindElementByElemPath(element_path);	
		if (NULL == ptr_element)
			return std::string("");

		return *ptr_element->Attribute(attribute_name);
	}

	bool CTinyXmlWrapper::SetElementAttribute( const std::string& element_path,
											   const std::string& attribute_name, 
											   const std::string& attribute_value )
	{
		TiXmlElement *ptr_element = FindElementByElemPath(element_path);	
		if (NULL == ptr_element)
			return NULL;

		ptr_element->SetAttribute(attribute_name, attribute_value);
		return true;
	}

	void CTinyXmlWrapper::PrintXml()
	{
		ptr_doc_->Print();
	}

	void CTinyXmlWrapper::Destory()
	{
		if(NULL != ptr_doc_)
			delete ptr_doc_;
	}



}

