/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"../state.hpp"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

namespace state{
    Element* ElementFactory::create(std::string clef, bool movable){
        if (movable!=true){
            return this->staticList.at(clef)->create(clef);
        }
        else
            return this->mobileList.at(clef)->create(clef);
    }
    
    void ElementFactory::enregistrer(std::string clef, IElement* creator, bool movable){
        if (movable!=true){
            this->staticList[clef]=unique_ptr<IElement>(creator);
        }
        else
            this->mobileList[clef]=unique_ptr<IElement>(creator);
    }
    
    ElementFactory::ElementFactory(){
        this->enregistrer("00",new FieldCreator, false);
        this->enregistrer("01",new FieldCreator, false);
        this->enregistrer("02",new FieldCreator, false);
        this->enregistrer("03",new FieldCreator, false);
        this->enregistrer("04",new FieldCreator, false);
        this->enregistrer("05",new FieldCreator, false);
        this->enregistrer("06",new FieldCreator, false);
        this->enregistrer("07",new FieldCreator, false);
        this->enregistrer("08",new FieldCreator, false);
        this->enregistrer("09",new FieldCreator, false);
        this->enregistrer("10",new FieldCreator, false);
        this->enregistrer("11",new FieldCreator, false);
        this->enregistrer("12",new FieldCreator, false);
        this->enregistrer("13",new FieldCreator, false);
        this->enregistrer("14",new FieldCreator, false);
        this->enregistrer("15",new FieldCreator, false);
        this->enregistrer("16",new FieldCreator, false);
        this->enregistrer("17",new FieldCreator, false);
        this->enregistrer("18",new FieldCreator, false);
        this->enregistrer("19",new FieldCreator, false);
        this->enregistrer("20",new FieldCreator, false);
        this->enregistrer("21",new FieldCreator, false);
        this->enregistrer("22",new FieldCreator, false);
        this->enregistrer("23",new FieldCreator, false);
        this->enregistrer("24",new FieldCreator, false);
        this->enregistrer("25",new FieldCreator, false);
        this->enregistrer("26",new FieldCreator, false);
        this->enregistrer("27",new FieldCreator, false);
        this->enregistrer("28",new FieldCreator, false);
        this->enregistrer("29",new FieldCreator, false);
        this->enregistrer("30",new FieldCreator, false);
        this->enregistrer("31",new FieldCreator, false);
        this->enregistrer("32",new FieldCreator, false);
        this->enregistrer("33",new FieldCreator, false);
        this->enregistrer("34",new FieldCreator, false);
        this->enregistrer("35",new FieldCreator, false);
        this->enregistrer("36",new FieldCreator, false);
        
        
        this->enregistrer("00",new FowlCreator, true);
        this->enregistrer("01",new FowlCreator, true);
        this->enregistrer("02",new FowlCreator, true);
        this->enregistrer("03",new FowlCreator, true);
        this->enregistrer("04",new FowlCreator, true);
        this->enregistrer("05",new FowlCreator, true);
        this->enregistrer("06",new FowlCreator, true);
        this->enregistrer("07",new FowlCreator, true);
        this->enregistrer("08",new FowlCreator, true);
        this->enregistrer("10",new FowlCreator, true);
        this->enregistrer("11",new FowlCreator, true);
        this->enregistrer("12",new FowlCreator, true);
        this->enregistrer("13",new FowlCreator, true);
        this->enregistrer("14",new FowlCreator, true);
        this->enregistrer("15",new FowlCreator, true);
        this->enregistrer("16",new FowlCreator, true);
        this->enregistrer("17",new FowlCreator, true);
        this->enregistrer("19",new FowlCreator, true);
        this->enregistrer("20",new FowlCreator, true);
        this->enregistrer("21",new FowlCreator, true);
        this->enregistrer("22",new FowlCreator, true);
        this->enregistrer("23",new FowlCreator, true);
        this->enregistrer("24",new FowlCreator, true);
        this->enregistrer("25",new FowlCreator, true);
        this->enregistrer("26",new FowlCreator, true);
        this->enregistrer("28",new FowlCreator, true);
        this->enregistrer("29",new FowlCreator, true);
        this->enregistrer("30",new FowlCreator, true);
        this->enregistrer("31",new FowlCreator, true);
        this->enregistrer("32",new FowlCreator, true);
        this->enregistrer("33",new FowlCreator, true);
        this->enregistrer("34",new FowlCreator, true);
        this->enregistrer("35",new FowlCreator, true);
        this->enregistrer("37",new FowlCreator, true);
        this->enregistrer("38",new FowlCreator, true);
        this->enregistrer("39",new FowlCreator, true);
        this->enregistrer("40",new FowlCreator, true);
        this->enregistrer("41",new FowlCreator, true);
        this->enregistrer("42",new FowlCreator, true);
        this->enregistrer("43",new FowlCreator, true);
        this->enregistrer("44",new FowlCreator, true);
        this->enregistrer("46",new FowlCreator, true);
        this->enregistrer("47",new FowlCreator, true);
        this->enregistrer("48",new FowlCreator, true);
        this->enregistrer("49",new FowlCreator, true);
        this->enregistrer("50",new FowlCreator, true);
        this->enregistrer("51",new FowlCreator, true);
        this->enregistrer("52",new FowlCreator, true);
        this->enregistrer("53",new FowlCreator, true);
        this->enregistrer("55",new FowlCreator, true);
        this->enregistrer("56",new FowlCreator, true);
        this->enregistrer("57",new FowlCreator, true);
        this->enregistrer("58",new FowlCreator, true);
        this->enregistrer("59",new FowlCreator, true);
        this->enregistrer("60",new FowlCreator, true);
        this->enregistrer("61",new FowlCreator, true);
        this->enregistrer("62",new FowlCreator, true);
        this->enregistrer("64",new FowlCreator, true);
        this->enregistrer("65",new FowlCreator, true);
        this->enregistrer("66",new FowlCreator, true);
        this->enregistrer("67",new FowlCreator, true);
        this->enregistrer("68",new FowlCreator, true);
        this->enregistrer("69",new FowlCreator, true);
        this->enregistrer("70",new FowlCreator, true);
        this->enregistrer("71",new FowlCreator, true);
        
    }
}
