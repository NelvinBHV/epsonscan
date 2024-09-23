//  Copyright (C) 2018-2022  SEIKO EPSON CORPORATION
//
//  License: LGPL-2.1+
//  Author : SEIKO EPSON CORPORATION
//
//  This file is part of the 'Epson Scan 2' package.
//	 This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.

//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  SkipBlankPage.hpp -- template and derived ESC/I ESC/I-2 protocol commands

#include "Key.hpp"
#include "EpsonScan2.h"
#include "DTR.hpp"
namespace epsonscan {
 class SkipBlankPage : public Key<SDIInt>
 {
  public:
  explicit SkipBlankPage(IKeyDataProvider* dataProvider) : Key<SDIInt>(dataProvider) , isSupportHardwareBlankPageLevel_(false)
  {
  }
  std::string GetName() const override
  {
   return std::string(kSDIBlankPageSkipLevelKey);
  }
  void SetValue(const SDIInt& intVal) override;
  void GetValue(SDIInt& outIntVal) override;
  void GetCapability(SDICapability &capability) override;
  void Reset() override;
  ESDictionary GetEngineKeyValues() override;
  bool IsSupportBlankPageLevel();
  private:
   bool isSupportHardwareBlankPageLevel_;
 };
}
