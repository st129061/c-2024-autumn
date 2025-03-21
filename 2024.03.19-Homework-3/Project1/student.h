#pragma once

#include <string>
#include <random>

#include "params.h"
#include "artefact.h"

class student
{
private:
    std::string Name;

    params Stats;
    artefact * Artefact;

public:
    student() = delete;
    student(std::string Name, params Stats, artefact * Artefact) : Name(Name), Stats(Stats), Artefact(Artefact)
    {
        if (!Artefact)
        {
            throw "student Artefact is nullptr";
        }

        Artefact->OnInit(Stats);
    }

    bool IsDeid( void ) const
    {
        return Stats.HealthPoint == 0;
    }

    std::string & GetName( void )
    {
        return Name;
    }
    params & GetStats( void )
    {
        return Stats;
    }


    uint GiveDamage( void )
    {
        Artefact->OnUse(Stats);

        uint rand_ = (uint)((double)rand() / RAND_MAX * 100);
        return Stats.BaseDamage * (1 + (rand_ > Stats.CritChance ? Stats.CritDamage / 100.0 : 0));
    }
    void GetDamage( uint Damage )
    {
        if (Stats.HealthPoint < Damage)
        {
            Stats.HealthPoint = 0;
        }
        else
        {
            Stats.HealthPoint -= Damage;
        }
    }
};