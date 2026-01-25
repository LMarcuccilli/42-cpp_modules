#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria *_materia[4];

    void cleanMateria();

public:
    MateriaSource();

    MateriaSource(const MateriaSource &other);

    MateriaSource &operator=(const MateriaSource &other);

    ~MateriaSource();

    void learnMateria(AMateria *);

    AMateria *createMateria(std::string const &type);
};

#endif
