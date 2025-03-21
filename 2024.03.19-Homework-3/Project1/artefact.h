#pragma once

#include <vector>

#include "params.h"

class property_base
{
public:
    virtual void OnUse( params &UpdateStats )
    {
    }
    virtual void OnInit( params &BaseStats )
    {
    }
};

class artefact
{
private:
    std::vector<property_base *> Property;
    
public:
    ~artefact( void )
    {
        for (auto &property: Property)
        {
            delete property;
        }
    }

    void OnInit( params &BaseStats )
    {
        for (auto &property: Property)
        {
            property->OnInit(BaseStats);
        }
    }

    void OnUse( params &UpdateStats )
    {
        for (auto &property: Property)
        {
            property->OnUse(UpdateStats);
        }
    }

    template<class T>
    artefact & Add( T &NewProperty )
    {
        static_assert(std::is_base_of<property_base, T>(), "artefact::Add can add only property");

        Property.push_back((property_base *)new T(NewProperty));

        return *this;
    }

};
