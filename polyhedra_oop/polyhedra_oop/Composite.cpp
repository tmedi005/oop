#include "Polyhedron.h"
#include "Composite.h"

/**
 *
 */
Composite::Composite()
    :Polyhedron("Composite"),
     numPolyhedra(0),
     polyhedra(nullptr)
{
}

/**
 *
 */
Composite::Composite(const Composite& src)
    :Polyhedron("Composite")
{
    this->numPolyhedra = src.numPolyhedra;
    this->polyhedra    = new Polyhedron*[numPolyhedra];

    for (int i = 0; i < numPolyhedra; i++) {
        this->polyhedra[i] = (src.polyhedra[i])->clone();
    }

    this->boundingBox = src.boundingBox;
}

/**
 *
 */
Composite::~Composite()
{
    if (polyhedra != nullptr) {
        for (int i = 0; i < numPolyhedra; i++) {
            delete this->polyhedra[i];
        }

        delete[] polyhedra;

        polyhedra = nullptr;
    }
}

/**
 *
 */
void Composite::read(std::istream& ins){
    ins >> numPolyhedra;

    polyhedra = new Polyhedron*[numPolyhedra];

    for (int i = 0; i < numPolyhedra; i++) {
        ins >> polyhedra[i];

        boundingBox.merge(polyhedra[i]->getBoundingBox());
    }
}

/**
 *
 */
void Composite::display(std::ostream& outs) const
{
    Polyhedron::display(outs);

    outs << numPolyhedra << " polyhedra" << "\n";

    for (int i = 0; i < numPolyhedra; i++) {
        //polyhedra[i]->display(outs);
        outs << "  " << (*polyhedra[i]) << "\n";
    }
}

/**
 *
 */
void Composite::scale(double scalingFactor)
{
    for (int i = 0; i < numPolyhedra; i++) {
        polyhedra[i]->scale(scalingFactor);
    }

    boundingBox.scale(scalingFactor);
}

/**
 *
 */
Composite& Composite::operator=(const Composite& rhs)
{
    if (this != &rhs) {
        if (polyhedra != nullptr) {
            for (int i = 0; i < numPolyhedra; i++) {
                delete this->polyhedra[i];
            }

            delete[] polyhedra;

            polyhedra = nullptr;
        }

        this->numPolyhedra = rhs.numPolyhedra;
        this->polyhedra    = new Polyhedron*[numPolyhedra];

        for (int i = 0; i < numPolyhedra; i++) {
            this->polyhedra[i] = (rhs.polyhedra[i])->clone();
        }

        this->boundingBox = rhs.boundingBox;
    }

    return *this;
}
