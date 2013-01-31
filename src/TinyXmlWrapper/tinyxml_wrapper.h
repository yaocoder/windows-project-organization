/**
 * @created:	   		2012/04/28
 *
 * @file				XmlWrapper\vcprojects\TinyXmlWrapper\TinyXmlWrapper.h
 *
 * @author  			wei yao <yaocoder@gmail.com>
 *
 * @version 			1.0
 *
 * @LICENSE 			GPL
 *
 * @brief				The Xml Operate implement by tinyxml  				
 *
 */

#ifndef TINY_XML_WRAPPER_H_
#define TINY_XML_WRAPPER_H_

#include <tinyxml/tinyxml.h>
#include <string>

namespace XmlOperate
{
	/**
	 * @brief   The wrapper by tinyxml 
	 */
	class CTinyXmlWrapper
	{
	public:
		CTinyXmlWrapper(void);
		~CTinyXmlWrapper(void);

	public:
		/**
		 * @brief load xml file
		 * @param [in]	the xml file name
		 * @return If successful true is returned, if not false is returned.
		 */
		bool			LoadXmlDocument(const std::string& file_name);

		/**
		 * @brief save xml file
		 * @return If successful true is returned, if not false is returned.
		 */
		bool			SaveXmlDocument();

		/**
		 * @brief		Get pointer used to operate element 		
		 * @param [in]  The path of xml element  : must by "&" join
		 * @return TiXmlElement*  for operate element 
		 */
		TiXmlElement*	FindElementByElemPath(const std::string& element_path);

		/**
		 * @brief		Get text of element
		 * @param [in]	The path of element 
		 * @return		The text of element  
		 */
		std::string		GetElementText(const std::string& element_path);

		/**
		 * @brief		Modify text of element
		 * @param [in]	The path of element	
		 * @param [in]	The new text of element 
		 * @return 
		 */
		bool			SetElementText(const std::string& element_path,
									   const std::string& new_text);

		/**
		 * @brief		Get value of the element's attribute
		 * @param [in]	The path of element	
		 * @param [in]	The name of the element's attribute
		 * @return 
		 */
		std::string		GetElementAttribute(const std::string& element_path,
											const std::string& attribute_name);

		/**
		 * @brief		Set value of the element's attribute
		 * @param [in]	The path of element	
		 * @param [in]	The name of the element's attribute
		 * @param [in]	The new value of the element's attribute
		 * @return 
		 */
		bool			SetElementAttribute(const std::string& element_path, 
											const std::string& attribute_name,
											const std::string& attribute_value);

		/**
		 * @brief Print the whole xml file
		 */
		void PrintXml();

		/**
		 * @brief		Release resource
		 */
		void Destory();

	private:

		TiXmlDocument* ptr_doc_;								 //the TiXmlDocument object 
	};
}


#endif

