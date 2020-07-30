#include "pugixml.hpp"
#include <iostream>
#include <string>

int main()
{
    pugi::xml_document doc;
    if (!doc.load_file("ex1.xml"))
    {
        return -1;
    }

    /*const char* c_szMsg */
    /* pugi::xml_parse_result result=doc.load_string(c_szMsg);
      if(!result)
      {
          return -1;
      }*/

#if 1
    std::cout <<"=============================[1]============================"<< std::endl;
    pugi::xpath_node_set node_set=doc.select_nodes("Message/Log/Record/Data/Division/Area[@Attach]");
    for(pugi::xpath_node_set::const_iterator it=node_set.begin(); it != node_set.end(); ++it)
    {
        pugi::xpath_node xpath_node = *it;
        pugi::xml_node piece=xpath_node.node();
        std::string attr_value= piece.attribute("Attach").value();
        std::cout <<attr_value << std::endl;
        std::cout <<"=========="<< std::endl;
        pugi::xml_node child_node=piece.child("Place");

        for(pugi::xml_node place=child_node; place ; place=place.next_sibling("Place"))
        {
            std::string place_attr_value1 =place.attribute("Line").value();
            std::string place_attr_value2 =place.attribute("KeyWord").value();
            std::string place_text_value =place.text().get();
            std::cout <<place_attr_value1 << std::endl;
            std::cout <<place_attr_value2 << std::endl;
            std::cout <<place_text_value << std::endl;
            std::cout <<"----------"<< std::endl;
        }

        std::cout <<"********************"<< std::endl;
    }
#endif
#if 1
    std::cout <<"=============================[2]============================"<< std::endl;
    pugi::xpath_node xpath_node_rare=doc.select_node("Message/Log/Record/Data/Animal/Rare");
    pugi::xml_node node_rare=xpath_node_rare.node();
    std::string rare=node_rare.text().get();

    pugi::xpath_node xpath_node_precious=doc.select_node("Message/Log/Record/Data/Animal/Precious");
    pugi::xml_node node_precious=xpath_node_precious.node();
    std::string precious=node_precious.text().get();

    pugi::xpath_node xpath_node_wild=doc.select_node("Message/Log/Record/Data/Animal/Wild");
    pugi::xml_node node_wild=xpath_node_wild.node();
    std::string wild=node_wild.text().get();

    std::cout <<rare << std::endl;
    std::cout <<precious << std::endl;
    std::cout <<wild << std::endl;

#endif

#if 1
    std::cout <<"=============================[3]============================"<< std::endl;
    pugi::xpath_query query_attach_total("Message/Log/Record/Data/Animal/Attach/@Total");
    std::string attach_total= query_attach_total.evaluate_string(doc);
    pugi::xpath_query query_attach_hit("Message/Log/Record/Data/Animal/Attach/@Hit");
    std::string attach_hit= query_attach_hit.evaluate_string(doc);

    std::cout <<attach_total << std::endl;
    std::cout <<attach_hit << std::endl;
    std::cout <<"==========" << std::endl;

    pugi::xpath_query query_attach("Message/Log/Record/Data/Animal/Attach/Item");
    pugi::xpath_node_set  attach_set=query_attach.evaluate_node_set(doc);
    for(pugi::xpath_node_set::const_iterator iter=attach_set.begin(); iter != attach_set.end(); ++iter)
    {
        pugi::xpath_node xpath_node = *iter;
        pugi::xml_node item=xpath_node.node();
        std::string attr_value1= item.attribute("SignName").value();
        std::string attr_value2= item.attribute("Hit").value();
        std::string item_text_value= item.text().get();
        std::cout <<attr_value1 << std::endl;
        std::cout <<attr_value2 << std::endl;
        std::cout <<item_text_value << std::endl;
        std::cout <<"----------"<< std::endl;
    }
#endif

#if 1
    std::cout <<"=============================[4]============================"<< std::endl;
    pugi::xpath_node xpath_node_dp_north=doc.select_node("Message/Log/Record/DaPai[@Name='North']");
    pugi::xml_node node_dp_north=xpath_node_dp_north.node();
    std::string dp_north=node_dp_north.text().get();

    pugi::xpath_node xpath_node_dp_south=doc.select_node("Message/Log/Record/DaPai[@Name='South']");
    pugi::xml_node node_dp_south=xpath_node_dp_south.node();
    std::string dp_south=node_dp_south.text().get();

    pugi::xpath_node xpath_node_dp_east=doc.select_node("Message/Log/Record/DaPai[@Name='East']");
    pugi::xml_node node_dp_east=xpath_node_dp_east.node();
    std::string dp_east=node_dp_east.text().get();

    pugi::xpath_query xpath_query_dp_level("Message/Log/Record/DaPai[@Name='Level']");
    std::string dp_level= xpath_query_dp_level.evaluate_string(doc);

    pugi::xpath_query xpath_query_dp_reason("Message/Log/Record/DaPai[@Name='Reason']");
    std::string dp_reason= xpath_query_dp_reason.evaluate_string(doc);

    pugi::xpath_query xpath_query_dp_tip("Message/Log/Record/DaPai[@Name='Tip']");
    std::string dp_tip= xpath_query_dp_tip.evaluate_string(doc);

    std::cout <<dp_north << std::endl;
    std::cout <<dp_south << std::endl;
    std::cout <<dp_east << std::endl;
    std::cout <<dp_level << std::endl;
    std::cout <<dp_reason << std::endl;
    std::cout <<dp_tip << std::endl;
#endif


}

