#pragma once

#include <vector>
#include <iostream>
#include <random>

#include "student.h"

class battle_system
{
private:
    std::vector<student> Left;
    std::vector<student> Right;

public:
    battle_system(const std::vector<student> Left, const std::vector<student> Right)
    {
        for (auto &s: Left)
        {
            AddLeft(s);
        }
        for (auto &s: Right)
        {
            AddRight(s);
        }
    }

    void AddLeft(const student &Student)
    {
        if (Student.IsDeid())
        {
            throw "battle_system add student is dead";
        }
        Left.push_back(Student);
    }
    void AddRight(const student &Student)
    {
        if (Student.IsDeid())
        {
            throw "battle_system add student is dead";
        }
        Right.push_back(Student);
    }

    void IndexAttack(std::vector<int> &LeftAttackIndex, std::vector<int> &RightAttackIndex)
    {
        for (int i = 0; i < Left.size(); ++i)
        {
            LeftAttackIndex[i] = (int)((double)i * (double)Right.size() / (double)Left.size());
        }
        for (int i = 0; i < Right.size(); ++i)
        {
            RightAttackIndex[i] = (int)((double)i * (double)Left.size() / (double)Right.size());
        }
    }

    void Print( void )
    {
        std::cout << "-----------------" << "\n";
        std::cout << "Left:" << "\n";
        for (auto &s: Left)
        {
            std::cout << "> " << s.GetName() << " " << s.GetStats().HealthPoint << "\n";
        }
        std::cout << "Right:" << "\n";
        for (auto &s: Right)
        {
            std::cout << "> "  << s.GetName() << " " << s.GetStats().HealthPoint << "\n";
        }
        std::cout << "-----------------" << "\n";
    }

    void Battle( void )
    {
        Print();

        bool turn = false;

        int rand_ = rand();
        double rand__ = (double)rand_ / RAND_MAX;
        rand_ = rand__ * 2;


        // (int)((double)rand() / RAND_MAX * 2.0);
        if (rand_ >= 1)
        {
            turn = true;
            std::cout << "Start Right\n";
        }
        else
        {
            std::cout << "Start Left\n";
        }

        std::vector<int> LeftAttackIndex(Left.size()), RightAttackIndex(Right.size());

        bool battle = Left.size() != 0 && Right.size() != 0;

        IndexAttack(LeftAttackIndex, RightAttackIndex);

        while (battle)
        {
            std::vector<student> &Attack = turn ? Right : Left;
            std::vector<int> &Goal = turn ? RightAttackIndex: LeftAttackIndex;
            std::vector<student> &Defending = turn ? Left : Right;

            turn = !turn;


            for (int i = 0; i < Attack.size() && battle; ++i)
            {
                int def_index = Goal[i];
                Defending[def_index].GetDamage(Attack[i].GiveDamage());

                if (Defending[def_index].IsDeid())
                {
                    std::cout << Attack[i].GetName() << " kill " << Defending[def_index].GetName() << "\n";
                    Defending.erase(Defending.begin() + def_index);
                    IndexAttack(LeftAttackIndex, RightAttackIndex);
                }

                battle = Left.size() != 0 && Right.size() != 0;
            }
            Print();
        }

        if (Left.size() != 0)
        {
            std::cout << "Left Win\n";
        }
        else
        {
            std::cout << "Right Win\n";
        }
    }
};