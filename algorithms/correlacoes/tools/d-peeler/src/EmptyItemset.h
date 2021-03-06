// Copyright 2007-2014 Loïc Cerf (magicbanana@gmail.com)

// This file is part of d-peeler.

// d-peeler is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License version 3 as published by the Free Software Foundation

// d-peeler is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with d-peeler; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

#ifndef EMPTY_ITEMSET_H_
#define EMPTY_ITEMSET_H_

#include "AbstractHyperBitset.h"

class EmptyItemset : public AbstractHyperBitset
{
    public:
        EmptyItemset(unsigned int bitsetSize);
        EmptyItemset& operator=(const EmptyItemset& otherItemset);

        AbstractHyperBitset* clone() const;

        unsigned int nbOfDimensions() const;
        unsigned int size() const;

        AbstractHyperBitset& bitwiseAndEqual(AbstractHyperBitset* otherAbstractHyperBitset);
        void setValue(const bool value = true);
        void setValue(const unsigned int& elementId, const bool value = true);
        void setValue(const vector<unsigned int> &tuple, const bool value = true);

        void setValue(vector<unsigned int>::const_iterator begin,
                vector<unsigned int>::const_iterator end,
                bool value);

        void setValues(const vector<vector<unsigned int> >& bits, const bool value = true);
        unsigned int count() const;
        vector<vector<vector<unsigned int> > > unidimensionalNRectangles(const vector<vector<unsigned int> >::iterator& elementsIt, const vector<vector<unsigned int> >::const_iterator& firstElementsIt, const vector<vector<unsigned int> >::const_iterator& pastTheLastElementsIt) const;
        bool includedIn(AbstractHyperBitset* otherAbstractHyperBitset) const;
        bool enough0On(int& threshold, const vector<vector<unsigned int> >::const_iterator& elementsIt) const;
        bool trueOn(const vector<vector<unsigned int> >::const_iterator& elementsIt) const;
        bool falseOn(const vector<vector<unsigned int> >::const_iterator& elementsIt) const;
        bool trueOnPotentialBits(const vector<vector<unsigned int> >::const_iterator& presentElementsIt, const vector<vector<unsigned int> >::const_iterator& potentialElementsIt, bool isPotentialElementUsed = false) const;
        unsigned int countOn(const vector<vector<unsigned int> >::const_iterator& elementsIt) const;
        unsigned int countAndCropOn(const vector<vector<unsigned int> >::const_iterator& elementsIt, const vector<vector<bool> >::iterator& coveringElementsIt) const;
        bool setPresent(const vector<vector<unsigned int> >::iterator& newAbsentElementsIt, const vector<vector<unsigned int> >::const_iterator& presentElementsIt, const vector<vector<unsigned int> >::iterator& potentialElementsIt, const bool isPotentialNotUsed = true) const;

        bool densityLimitViolated() const;

        AbstractHyperBitset* cloneAsDenserHyperBitset() const;
    private:
        unsigned bitsetSize;
};

#endif /* EMPTY_ITEMSET_H_ */
