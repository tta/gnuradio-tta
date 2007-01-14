/* -*- c++ -*- */
/*
 * Copyright 2006 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef INCLUDED_MB_RUNTIME_IMPL_H
#define INCLUDED_MB_RUNTIME_IMPL_H

#include <mb_common.h>

/*!
 * \brief The private implementation details of the runtime system.
 */
class mb_runtime_impl : boost::noncopyable
{
private:
  friend class mb_runtime;

  mb_runtime_impl();

public:
  ~mb_runtime_impl();
};


#endif /* INCLUDED_MB_RUNTIME_IMPL_H */