/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"../state.hpp"
#include "FowlColor.h"
#include "FowlStatus.h"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

namespace state{
    Element* ElementFactory::create(std::string clef, bool movable){
        if (movable!=true){
            return this->staticList.at(clef)->create();
        }
        else
            return this->mobileList.at(clef)->create();
    }
    
    void ElementFactory::enregistrer(std::string clef, IElement* creator, bool movable){
        if (movable!=true){
            this->staticList[clef]=unique_ptr<IElement>(creator);
        }
        else
            this->mobileList[clef]=unique_ptr<IElement>(creator);
    }
    
    ElementFactory::ElementFactory(){
        this->enregistrer("00",new FieldCreator(FieldTypeID::BIGBROWN1), false);
        this->enregistrer("01",new FieldCreator(FieldTypeID::BIGBROWN2), false);
        this->enregistrer("02",new FieldCreator(FieldTypeID::BIGBROWN3), false);
        this->enregistrer("03",new FieldCreator(FieldTypeID::CIRCLEBROWN1), false);
        this->enregistrer("04",new FieldCreator(FieldTypeID::CIRCLEBROWN2), false);
        this->enregistrer("05",new FieldCreator(FieldTypeID::SMALLBROWN1), false);
        this->enregistrer("06",new FieldCreator(FieldTypeID::SMALLBROWN2), false);
        this->enregistrer("07",new FieldCreator(FieldTypeID::SMALLBROWN3), false);
        this->enregistrer("08",new FieldCreator(FieldTypeID::SMALLBROWN4), false);
        this->enregistrer("09",new FieldCreator(FieldTypeID::BIGBROWN4), false);
        this->enregistrer("10",new FieldCreator(FieldTypeID::BIGBROWN5), false);
        this->enregistrer("11",new FieldCreator(FieldTypeID::BIGBROWN6), false);
        this->enregistrer("12",new FieldCreator(FieldTypeID::CIRCLEBROWN3), false);
        this->enregistrer("13",new FieldCreator(FieldTypeID::CIRCLEBROWN4), false);
        this->enregistrer("14",new FieldCreator(FieldTypeID::SMALLBROWN5), false);
        this->enregistrer("15",new FieldCreator(FieldTypeID::SMALLBROWN6), false);
        this->enregistrer("16",new FieldCreator(FieldTypeID::SMALLBROWN7), false);
        this->enregistrer("17",new FieldCreator(FieldTypeID::SMALLBROWN8), false);
        this->enregistrer("18",new FieldCreator(FieldTypeID::BIGSTONE1), false);
        this->enregistrer("19",new FieldCreator(FieldTypeID::BIGSTONE2), false);
        this->enregistrer("20",new FieldCreator(FieldTypeID::BIGSTONE3), false);
        this->enregistrer("21",new FieldCreator(FieldTypeID::CIRCLESTONE1), false);
        this->enregistrer("22",new FieldCreator(FieldTypeID::CIRCLESTONE2), false);
        this->enregistrer("23",new FieldCreator(FieldTypeID::SMALLSTONE1), false);
        this->enregistrer("24",new FieldCreator(FieldTypeID::SMALLSTONE2), false);
        this->enregistrer("25",new FieldCreator(FieldTypeID::SMALLSTONE3), false);
        this->enregistrer("26",new FieldCreator(FieldTypeID::SMALLSTONE4), false);
        this->enregistrer("27",new FieldCreator(FieldTypeID::BIGSTONE4), false);
        this->enregistrer("28",new FieldCreator(FieldTypeID::BIGSTONE5), false);
        this->enregistrer("29",new FieldCreator(FieldTypeID::BIGSTONE6), false);
        this->enregistrer("30",new FieldCreator(FieldTypeID::CIRCLESTONE3), false);
        this->enregistrer("31",new FieldCreator(FieldTypeID::CIRCLESTONE4), false);
        this->enregistrer("32",new FieldCreator(FieldTypeID::SMALLSTONE5), false);
        this->enregistrer("33",new FieldCreator(FieldTypeID::SMALLSTONE6), false);
        this->enregistrer("34",new FieldCreator(FieldTypeID::SMALLSTONE7), false);
        this->enregistrer("35",new FieldCreator(FieldTypeID::SMALLSTONE8), false);
        this->enregistrer("36",new FieldCreator(FieldTypeID::NEANT), false);
        
        
        this->enregistrer("00",new FowlCreator(FowlColor::BLANK,FowlStatus::NOTHING), true);
        this->enregistrer("01",new FowlCreator(FowlColor::WHITE,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("03",new FowlCreator(FowlColor::WHITE,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("06",new FowlCreator(FowlColor::WHITE,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("08",new FowlCreator(FowlColor::WHITE,FowlStatus::DEAD), true);
        this->enregistrer("10",new FowlCreator(FowlColor::GREEN,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("12",new FowlCreator(FowlColor::GREEN,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("15",new FowlCreator(FowlColor::GREEN,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("17",new FowlCreator(FowlColor::GREEN,FowlStatus::DEAD), true);
        this->enregistrer("19",new FowlCreator(FowlColor::BLACK,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("21",new FowlCreator(FowlColor::BLACK,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("24",new FowlCreator(FowlColor::BLACK,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("26",new FowlCreator(FowlColor::BLACK,FowlStatus::DEAD), true);
        this->enregistrer("28",new FowlCreator(FowlColor::BEIGE,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("30",new FowlCreator(FowlColor::BEIGE,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("33",new FowlCreator(FowlColor::BEIGE,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("35",new FowlCreator(FowlColor::BEIGE,FowlStatus::DEAD), true);
        this->enregistrer("37",new FowlCreator(FowlColor::KHAKI,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("39",new FowlCreator(FowlColor::KHAKI,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("42",new FowlCreator(FowlColor::KHAKI,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("44",new FowlCreator(FowlColor::KHAKI,FowlStatus::DEAD), true);
        this->enregistrer("46",new FowlCreator(FowlColor::BROWN,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("48",new FowlCreator(FowlColor::BROWN,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("51",new FowlCreator(FowlColor::BROWN,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("53",new FowlCreator(FowlColor::BROWN,FowlStatus::DEAD), true);
        this->enregistrer("55",new FowlCreator(FowlColor::GREY,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("57",new FowlCreator(FowlColor::GREY,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("60",new FowlCreator(FowlColor::GREY,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("62",new FowlCreator(FowlColor::GREY,FowlStatus::DEAD), true);
        this->enregistrer("64",new FowlCreator(FowlColor::ORANGE,FowlStatus::ALIVE_FACE), true);
        this->enregistrer("66",new FowlCreator(FowlColor::ORANGE,FowlStatus::ALIVE_LEFT), true);
        this->enregistrer("69",new FowlCreator(FowlColor::ORANGE,FowlStatus::ALIVE_RIGHT), true);
        this->enregistrer("71",new FowlCreator(FowlColor::ORANGE,FowlStatus::DEAD), true);
        
        this->enregistrer("02",new WeaponCreator(WeaponStatus::MELEE,false), true);
    }
}
