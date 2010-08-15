/**
 * Copyright (c) 2010 Daniel Wiberg
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef CANVAS_CONTEXT_HEADER
#define CANVAS_CONTEXT_HEADER

#include <core/SkBitmap.h>
#include <core/SkDevice.h>
#include <core/SkPaint.h>
#include <core/SkPath.h>
#include <core/SkPaint.h>

#include <list>
#include <cassert>

#include "State.h"
#include "ColorParser.h"

namespace canvas
{
   class ContextData;
   
   class Context
   {
      public:
         Context(int width, int height);
         ~Context();
         
         void copyImageTo(void * target);
         
         int width() const { return m_width; }
         /// Only here because binding system must have a get/set pair.
         void setWidth(int);
         
         int height() const { return m_height; }
         /// Only here because binding system must have a get/set pair.
         void setHeight(int);
         
         // Styles
         float lineWidth() const;
         void setLineWidth(float width);
         
         std::string lineCap() const;
         void setLineCap(std::string const& cap);
         
         std::string strokeStyle() const;
         void setStrokeStyle(std::string const& style);
         std::string fillStyle() const;
         void setFillStyle(std::string const& style);         
         
         // Transformations
         void scale(float x, float y);
         void rotate(float angle);
         void translate(float x, float y);
         
         // Path functions
         void beginPath();
         void closePath();
         
         void fill();
         void stroke();
         void clip();
         
         void moveTo(float x, float y);
         void lineTo(float x, float y);
         
         void fillRect(float x, float y, float width, float height);
         void strokeRect(float x, float y, float width, float height);
         
      private:
         inline State & currentState() { return m_stateStack.back(); }
         inline State const& currentState() const { return m_stateStack.back(); }
        
      private:
         SkBitmap * m_bitmap;
         SkDevice * m_device;
         SkCanvas * m_canvas;
         SkPath m_path;
         
         SkPaint m_fillPaint;
         SkPaint m_strokePaint;
         
         ColorParser m_parser;
         
         int m_width;
         int m_height;
         
         std::list<State> m_stateStack;
   };
   
}

#endif

