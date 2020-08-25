#include <iostream>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
using namespace pugi;
using namespace std;

bool ReadXml(const string fileName)
{
    xml_document doc;
    if (!doc.load_file(fileName.c_str())) { //加载xml文件
        cout << "load file faild";
        return false;
    }
    xml_node root = doc.child("root");  //根节点
    cout << "id:" << root.attribute("id").value() << endl;  //属性值

    xml_node node1 = root.child("oldman");
    cout << "name:" << node1.attribute("name").value() << "  age:" <<
        node1.attribute("age").value() << "  weight:" << node1.attribute("weight").value() << endl;

    xml_node node2 = root.child("guest");
    
   for (xml_node node = node2.first_child(); node != NULL; node = node.next_sibling())
    {  
        cout << "name:" << node.child("name").text().as_string() << endl;   //字符型
        cout << "age:" << node.child("age").text().as_int() << endl;        //整型
    }

    return true;
}


bool WriteXml(const string fileName)
{
    xml_document doc;
    //xml声明部分
    xml_node declaration_node = doc.append_child(pugi::node_declaration);
    declaration_node.append_attribute("version") = "1.0";
    declaration_node.append_attribute("encoding") = "UTF-8";

    pugi::xml_node root = doc.append_child("root"); //根节点
    root.append_attribute("id") = "S1"; //根节点属性

    for (int i = 0; i < 3; ++i) {
        xml_node node = root.append_child("count");
        node.append_attribute("x") = i;
        node.append_attribute("y").set_value(i);
        node.text().set("node");
    }
    root.append_child("name").text().set("yangxiaoben");
    doc.save_file(fileName.c_str());

    return true;
}


void ChangeXml(const string fileName)
{
    xml_document doc;
    if (!doc.load_file(fileName.c_str())) { //加载xml文件
        cout << "load file faild";
        return ;
    }

     pugi::xpath_node_set node_set=doc.select_nodes("root/person");
     for(pugi::xpath_node_set::const_iterator it=node_set.begin(); it != node_set.end(); ++it)
     {
         pugi::xpath_node xpath_node = *it;
         pugi::xml_node xml_node=xpath_node.node();
         /*std::cout <<attr_value << std::endl;*/

         pugi::xml_node node_name=xml_node.child("name");
         std::string node_text_name_value =node_name.text().get();
         if("lisi" == node_text_name_value)
         {

         pugi::xml_node node_age=xml_node.child("age");
         std::string node_text_value =node_age.text().get();

         pugi::xml_attribute xml_attr_young=node_age.attribute("young");

         const char*  nodeName=xml_node.name();
         std::cout <<"nodeName:"<<nodeName << std::endl;
         std::cout <<"node_text_value:"<<node_text_value << std::endl;
         std::cout <<"xml_attr_young:"<<xml_attr_young.value() << std::endl;


         node_age.text().set("married");
         node_age.text().set("married");


         xml_attr_young.set_value("100");


         node_text_value =node_age.text().get();

         std::cout <<"nodeName:"<<nodeName << std::endl;
         std::cout <<"node_text_value:"<<node_text_value << std::endl;
         std::cout <<"xml_attr_young:"<<xml_attr_young.value() << std::endl;

         }


     }

    doc.save_file(fileName.c_str()," ",pugi::format_indent,pugi::encoding_utf8);
}


void addXmlNode(const string fileName)
{
    xml_document doc;
    if (!doc.load_file(fileName.c_str())) { //加载xml文件
        cout << "load file faild";
        return ;
    }

     pugi::xpath_node xpath_node=doc.select_node("root");
     pugi::xml_node  xml_node=xpath_node.node();
     pugi::xml_node xml_node_person=xml_node.append_child("person");
     pugi::xml_node xml_node_age=xml_node_person.append_child("age");
     pugi::xml_node xml_node_school=xml_node_person.append_child("school");
     pugi::xml_node xml_node_name=xml_node_person.append_child("name");

     pugi::xml_attribute xml_attr_young=xml_node_age.append_attribute("young");
     pugi::xml_attribute xml_attr_adult=xml_node_age.append_attribute("adult");
     xml_attr_young.set_value("12");
     xml_attr_adult.set_value("50");

     pugi::xml_attribute xml_attr_city=xml_node_school.append_attribute("city");
     pugi::xml_attribute xml_attr_home=xml_node_school.append_attribute("home");
     xml_attr_city.set_value("qingdao");
     xml_attr_home.set_value("dalian");
     xml_node_school.text().set("hengzhong");

     xml_node_name.text().set("zhangzheng");

     pugi::xpath_query  query_node("root/person");
     pugi::xpath_node_set node_set= query_node.evaluate_node_set(doc);


     for(pugi::xpath_node_set::const_iterator it=node_set.begin(); it != node_set.end(); ++it)
     {
         pugi::xpath_node xpath_node = *it;
         pugi::xml_node xml_node=xpath_node.node();

         pugi::xml_node node_name=xml_node.child("name");
         std::string node_text_name_value =node_name.text().get();
         if("lisi" == node_text_name_value)
         {

         pugi::xml_node node_age=xml_node.child("age");
         std::string node_text_value =node_age.text().get();

         pugi::xml_attribute xml_attr_young=node_age.attribute("young");
         pugi::xml_attribute xml_attr_adult=node_age.attribute("adult");

         const char*  nodeName=xml_node.name();
         std::cout <<"nodeName:"<<nodeName << std::endl;
         std::cout <<"node_text_value:"<<node_text_value << std::endl;
         std::cout <<"xml_attr_young:"<<xml_attr_young.value() << std::endl;
         std::cout <<"xml_attr_adult:"<<xml_attr_adult.value() << std::endl;

         }


     }

    doc.save_file(fileName.c_str()," ",pugi::format_indent,pugi::encoding_utf8);
}



void deleteXmlNode(const string fileName)
{
    xml_document doc;
    if (!doc.load_file(fileName.c_str())) { //加载xml文件
        cout << "load file faild";
        return ;
    }


     pugi::xpath_query  query_node("root/person");
     pugi::xpath_node_set node_set= query_node.evaluate_node_set(doc);


     for(pugi::xpath_node_set::const_iterator it=node_set.begin(); it != node_set.end(); ++it)
     {
         pugi::xpath_node xpath_node = *it;
         pugi::xml_node xml_node=xpath_node.node();

         pugi::xml_node node_name=xml_node.child("name");
         std::string node_text_name_value =node_name.text().get();
         std::cout <<"node_text_name_value:"<<node_text_name_value << std::endl;

         pugi::xml_node node_age=xml_node.child("age");
         std::string node_text_value =node_age.text().get();

         pugi::xml_attribute xml_attr_young=node_age.attribute("young");
         pugi::xml_attribute xml_attr_adult=node_age.attribute("adult");

         const char*  nodeName=xml_node.name();
         std::cout <<"nodeName:"<<nodeName << std::endl;
         std::cout <<"node_text_value:"<<node_text_value << std::endl;
         std::cout <<"xml_attr_young:"<<xml_attr_young.value() << std::endl;
         std::cout <<"xml_attr_adult:"<<xml_attr_adult.value() << std::endl;

         if("married"==node_text_value)
         {
             node_age.parent().parent().remove_child(xml_node);
         }


     }

    doc.save_file(fileName.c_str()," ",pugi::format_indent,pugi::encoding_utf8);
}


int main()
{
#if 0
    string readFileName = "read.xml";
    ReadXml(readFileName);
    string writeFileName = "write.xml";
    WriteXml(writeFileName);
   
    string changeFileName = "change.xml";
    ChangeXml(changeFileName);

    string addFileName = "add.xml";
    addXmlNode(addFileName);
 #endif

    string deleteFileName = "delete.xml";
    deleteXmlNode(deleteFileName);
   
    return 0;
}

