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

#ifndef TsFilterHub_hh
#define TsFilterHub_hh

#include "G4String.hh"
#include "G4Types.hh"

class TsParameterManager;
//class TsExtensionManager;
class TsMaterialManager;
class TsGeometryManager;
class TsFilterManager;

class TsVFilter;
class TsVGenerator;
class TsVScorer;

class TsFilterHub
{
public:
	TsFilterHub();
	~TsFilterHub();

	//TsVFilter* InstantiateFilter(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM,
	//							 TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer);
	TsVFilter* InstantiateFilter(TsParameterManager* pM, TsMaterialManager* mM, TsGeometryManager* gM, TsFilterManager* fM, TsVGenerator* generator, TsVScorer* scorer);

private:
	G4bool HaveFilterNamed(TsParameterManager* pM, TsVGenerator* generator, TsVScorer* scorer, G4String filterName);
};
#endif
