#include "Gene.h"
#include <iostream>

Gene::Gene()
{
 	char temp [0];
	setData(temp, 0);
	added = false;
	size = 0;
}

Gene::Gene(string str)
{
	char temp [str.size()];

	for(unsigned int i = 0; i < str.size(); i++)
	{
		temp[i] = str[i];
	}
	
	setData(temp, str.size());
	added = false;
	size = str.size();
}

Gene::Gene(String str)
{
	setDataP(str.getData(),str.length());
	added = false;
	size = str.length();
}

int Gene::getSize()
{
	return size;
}

void Gene::build(Gene allseq[], int counter, int &addedCounter, int minOverlap)
{
	// looking at beginning of builder
	String builderFirstSegment(this->subString(0, minOverlap));
	int index(0);
	// iterate through all sequences
	for(int j = 1; j < counter -1; j++)
	{
		// If havent already looked at the gene operate
		if(allseq[j].added == false){
			// stupid copying
			char* firstSegmentTemp = new char[minOverlap];
			firstSegmentTemp = builderFirstSegment.getData();
			char firstSegmentTemp2[minOverlap + 1];
			for(int k = 0; k < minOverlap; k++)
			{
				firstSegmentTemp2[k] = firstSegmentTemp[k];
			}
			firstSegmentTemp2[minOverlap] = '\0';

			// Find the first 20 somewhere in another sequence
			index = allseq[j].find(firstSegmentTemp2, 0);

			//Found one?
			if(index != -1)
			{
				String comp(allseq[j].subString(index + minOverlap, allseq[j].length()-index-minOverlap));
				String builderSub(this->subString(minOverlap, allseq[j].length() - index - minOverlap));
				//if we have a match we add overhang to builder string
				if(comp == builderSub)
				{
					*this = Gene(allseq[j].subString(0, index)) + *this;
					builderFirstSegment = this->subString(0, minOverlap);
					allseq[j].added = true;
					addedCounter++;
				}
			}
		}
	}

	// looking at end of builder if couldn't add to beginning
	String builderLastSegment(this->subString(this->length() - minOverlap, minOverlap));
	index=0;
    for(int j = 1; j < counter -1; j++)
	{
		if(allseq[j].added == false)
		{
		    char* lastSegmentTemp = new char[minOverlap];
		    lastSegmentTemp = builderLastSegment.getData();
		    char lastSegmentTemp2[minOverlap + 1];
		    for(int j = 0; j < minOverlap; j++)
		    {
		        lastSegmentTemp2[j] = lastSegmentTemp[j];
		    }
		    lastSegmentTemp2[minOverlap] = '\0';
		    index = allseq[j].find(lastSegmentTemp2, 0);
		    if(index != -1)
		    {
			String comp(allseq[j].subString(0, index));
			String buildersub(this->subString(this->length() - minOverlap - comp.length(), comp.length()));
				if(comp == buildersub)
				{
			    	*this = *this + Gene(allseq[j].subString(index + minOverlap, allseq[j].length() - index - minOverlap));
		    	    builderLastSegment = this->subString(this->length() - minOverlap, minOverlap);
    			    allseq[j].added = true;
			    	addedCounter++;
				}
		    }
		}
	}
}
