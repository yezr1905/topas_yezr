//
// ********************************************************************
// *                                                                  *
// * Copyright 2022 The TOPAS Collaboration                           *
// *                                                                  *
// * Permission is hereby granted, free of charge, to any person      *
// * obtaining a copy of this software and associated documentation   *
// * files (the "Software"), to deal in the Software without          *
// * restriction, including without limitation the rights to use,     *
// * copy, modify, merge, publish, distribute, sublicense, and/or     *
// * sell copies of the Software, and to permit persons to whom the   *
// * Software is furnished to do so, subject to the following         *
// * conditions:                                                      *
// *                                                                  *
// * The above copyright notice and this permission notice shall be   *
// * included in all copies or substantial portions of the Software.  *
// *                                                                  *
// * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *
// * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *
// * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND         *
// * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT      *
// * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,     *
// * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
// * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    *
// * OTHER DEALINGS IN THE SOFTWARE.                                  *
// *                                                                  *
// ********************************************************************
//

#include "TsFilterByWeight.hh"

TsFilterByWeight::TsFilterByWeight(G4String name, TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM,
								   TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer, TsVFilter* parentFilter, G4bool invert, G4int test)
:TsVFilter(name, pM, mM, gM, fM, generator, scorer, parentFilter, invert), fTest(test) {
	ResolveParameters();
}


TsFilterByWeight::~TsFilterByWeight()
{;}


void TsFilterByWeight::ResolveParameters() {
	fWeight = fPm->GetUnitlessParameter(GetFullParmName(GetName()));
	TsVFilter::ResolveParameters();
}


G4bool TsFilterByWeight::Accept(const G4Step* aStep) const {
	if (fParentFilter && !fParentFilter->Accept(aStep)) return false;

	switch (fTest) {
		case 1 :
			if (aStep->GetTrack()->GetWeight() < fWeight) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (aStep->GetTrack()->GetWeight() == fWeight) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (aStep->GetTrack()->GetWeight() > fWeight) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}


G4bool TsFilterByWeight::AcceptTrack(const G4Track* aTrack) const {
	if (fParentFilter && !fParentFilter->AcceptTrack(aTrack)) return false;

	switch (fTest) {
		case 1 :
			if (aTrack->GetWeight() < fWeight) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 2 :
			if (aTrack->GetWeight() == fWeight) {
				if (fInvert) return false;
				else return true;
			}
			break;
		case 3 :
			if (aTrack->GetWeight() > fWeight) {
				if (fInvert) return false;
				else return true;
			}
	}

	if (fInvert) return true;
	else return false;
}
