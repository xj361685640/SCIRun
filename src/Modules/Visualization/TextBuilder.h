/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2012 Scientific Computing and Imaging Institute,
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

#ifndef MODULES_VISUALIZATION_MATRIX_AS_VECTOR_FIELD_H
#define MODULES_VISUALIZATION_MATRIX_AS_VECTOR_FIELD_H

#include <Core/Datatypes/Geometry.h>
#include <cstring>
#include <vector>

namespace SCIRun {
namespace Modules {
namespace Visualization {

class TextBuilder {
  public:
    TextBuilder(const char * text = "", const double scale = 1.,
                const Core::Geometry::Vector shift = Core::Geometry::Vector());
    virtual ~TextBuilder();
    void reset(const char * text, const double scale,
            const Core::Geometry::Vector shift);
    void getStringVerts(std::vector<Core::Geometry::Vector> &verts,  std::vector<Core::Geometry::Vector> &colors);
  private:
    std::string text_;
    double scale_;
    Core::Geometry::Vector shift_;
    void getCharVerts(const char c, std::vector<Core::Geometry::Vector> &verts,  std::vector<Core::Geometry::Vector> &colors);
    //four fonts to choose from.
    uint16_t *font0_;
    size_t font0_w_, font0_h_;
  };
}}}

#endif