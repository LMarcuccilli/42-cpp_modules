#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        _materia[i] = 0;
        if (other._materia[i] != 0)
            _materia[i] = other._materia[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        cleanMateria();
        for (int i = 0; i < 4; i++)
        {
            _materia[i] = 0;
            if (other._materia[i] != 0)
                _materia[i] = other._materia[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    cleanMateria();
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = materia->clone();
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && type == _materia[i]->getType())
            return _materia[i]->clone();
    }
    return 0;
}

void MateriaSource::cleanMateria()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] != 0)
        {
            delete _materia[i];
            _materia[i] = 0;
        }
    }
}
