
/*
   For more information, please see: http://software.sci.utah.edu
   The MIT License
   Copyright (c) 2015 Scientific Computing and Imaging Institute,
   University of Utah.
   License for the specific language governing rights and limitations under
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:
   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#include <Modules/BrainStimulator/ModelTMSCoilSingle.h>
#include <Interface/Modules/BrainStimulator/ModelTMSCoilSingleDialog.h>
#include <Core/Algorithms/BrainStimulator/ModelGenericCoilAlgorithm.h>
#include <Dataflow/Network/ModuleStateInterface.h>

using namespace SCIRun::Gui;
using namespace SCIRun::Dataflow::Networks;
using namespace SCIRun::Core::Algorithms;
using namespace SCIRun::Core::Algorithms::BrainStimulator;

ModelTMSCoilSingleDialog::ModelTMSCoilSingleDialog(const std::string& name, ModuleStateHandle state,
  QWidget* parent /* = 0 */)
  : ModuleDialogGeneric(state, parent)
{
  setupUi(this);
  setWindowTitle(QString::fromStdString(name));
  fixSize();
  addRadioButtonGroupManager({ CircularRadioButton_, Fig8RadioButton_}, Parameters::FigureOf8CoilShape);
  addDoubleSpinBoxManager(Current_, Parameters::Current);
  addDoubleSpinBoxManager(Radius_, Parameters::Radius);
  addDoubleSpinBoxManager(Distance_, Parameters::Distance);
  addSpinBoxManager(Layers_, Parameters::Layers);
  addDoubleSpinBoxManager(LayerStepSize_, Parameters::LayerStepSize);
  addSpinBoxManager(LevelOfDetail_, Parameters::LevelOfDetail);
}
