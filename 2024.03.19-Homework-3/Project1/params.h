#pragma once

typedef unsigned int uint;

struct params
{
    uint HealthPoint;
    uint BaseDamage;
    /* from 1 to 100 */
    uint CritChance;
    /* from 1 to ... */
    uint CritDamage;
    
    params() = delete;
                                                                           // , double coef = 1
    params(uint HealthPoint, uint BaseDamage, uint CritChance, uint CritDamage) : 
        HealthPoint(HealthPoint), BaseDamage(BaseDamage), CritChance(CritChance), CritDamage(CritDamage)
    {}

    

    /* damage = BaseDamage * (1 + CritDamage / 100 if crit)*/
};