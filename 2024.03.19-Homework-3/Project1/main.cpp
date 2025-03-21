
#include <iostream>
#include <ctime>

#include "artefact.h"
#include "student.h"
#include "battle_system.h"

class heal : property_base
{
private:
    uint HealHp;

public:
    heal( uint HealHp ) : HealHp(HealHp)
    {}

    void OnUse( params &Params ) override
    {
        std::cout << "Healing " << HealHp << " hp" << "\n";
        Params.HealthPoint += HealHp;
    }
};

class damage : property_base
{
private:
    uint AddDamage;

public:
    damage( uint AddDamage ) : AddDamage(AddDamage)
    {}

    void OnInit( params &Params ) override
    {
        Params.BaseDamage += AddDamage;
    }
};

class random_thing : property_base
{
private:
    params DeltaParams;

public:
    random_thing() : DeltaParams(0, 0, 0, 0)
    {}

    void OnInit( params &Params ) override
    {
        int rand_ = 0;

        rand_ = (double)rand() * 100.0 / RAND_MAX;
        DeltaParams.HealthPoint = rand_;
        rand_ = (double)rand() * 20.0 / RAND_MAX;
        DeltaParams.BaseDamage = rand_;
        rand_ = (double)rand() * 20.0 / RAND_MAX;
        DeltaParams.CritChance = rand_;
        rand_ = (double)rand() * 50.0 / RAND_MAX;
        DeltaParams.CritDamage = rand_;
    }
    void OnUse( params &Params ) override
    {
        int rand_ = (double)rand() * 5.0 / RAND_MAX;

        switch (rand_)
        {
        case 0:
            Params.HealthPoint += DeltaParams.HealthPoint;
            std::cout << "Healing " << DeltaParams.HealthPoint << " hp" << "\n";
            break;
        case 1:
            Params.BaseDamage += DeltaParams.BaseDamage;
            std::cout << "Boost " << DeltaParams.BaseDamage << " damage" << "\n";
            break;
        case 2:
            Params.CritChance += DeltaParams.CritChance;
            std::cout << "Boost " << DeltaParams.CritChance << " crit chance" << "\n";
            break;
        case 3:
            Params.CritDamage += DeltaParams.CritDamage;
            std::cout << "Boost " << DeltaParams.CritDamage << " crit chance" << "\n";
            break;
        default:
            break;
        }
    }
};



int main( int argv, char ** argc )
{
    heal Heal(20);
    damage Damage(15);
    random_thing Random;

    artefact HealArtefact;
    artefact DamageArtefact;

    HealArtefact.Add(Heal);
    DamageArtefact.Add(Damage);

    student A("Aba", params(100, 20, 20, 40), &HealArtefact);
    student B("Boba", params(130, 25, 10, 50), &DamageArtefact);

    srand(time(0));

    battle_system Battle({A}, {B});

    Battle.Battle();

    artefact RandomArtefacts[10];

    for (auto &ra: RandomArtefacts)
    {
        ra.Add(Random);
    }

    student RandomStudents[10] = 
    {
        {"RandomForce0", params(100, 20, 20, 40), RandomArtefacts + 0},
        {"RandomForce1", params(100, 20, 20, 40), RandomArtefacts + 1},
        {"RandomForce2", params(100, 20, 20, 40), RandomArtefacts + 2},
        {"RandomForce3", params(100, 20, 20, 40), RandomArtefacts + 3},
        {"RandomForce4", params(100, 20, 20, 40), RandomArtefacts + 4},
        {"RandomForce5", params(100, 20, 20, 40), RandomArtefacts + 5},
        {"RandomForce6", params(100, 20, 20, 40), RandomArtefacts + 6},
        {"RandomForce7", params(100, 20, 20, 40), RandomArtefacts + 7},
        {"RandomForce8", params(100, 20, 20, 40), RandomArtefacts + 8},
        {"RandomForce9", params(100, 20, 20, 40), RandomArtefacts + 9},
    };

    battle_system NewBattle({A, RandomStudents[0], RandomStudents[1], RandomStudents[2], RandomStudents[3], RandomStudents[4]}, 
        {B, RandomStudents[5], RandomStudents[6], RandomStudents[7], RandomStudents[8], RandomStudents[9]});

    NewBattle.Battle();

    return EXIT_SUCCESS;
}