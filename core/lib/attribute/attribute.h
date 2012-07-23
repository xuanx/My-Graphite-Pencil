/* =====================================================================================
 *
 *       Filename:  attri.h
 *
 *    Description:  definite attribute
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 18时03分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * ===================================================================================== */
#ifndef ATTRI_H
#define ATTRI_H

#include <map>
using std::map;

template<class Name, class Value>
class attribute: public map<Name, Value> {
public:
    attribute& operator () (const Name& name, const Value& value) {
        map<Name, Value>::operator [] (name) = value;
        return *this;
    }
    attribute& operator -  (const Name& name) {
        map<Name, Value>::erase(name);
        return *this;    
    }
};

#endif
