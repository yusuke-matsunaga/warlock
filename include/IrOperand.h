#ifndef IROPERAND_H
#define IROPERAND_H

/// @file IrOperand.h
/// @brief IrOperand のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2020 Yusuke Matsunaga
/// All rights reserved.


#include "warlock.h"


BEGIN_NAMESPACE_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class IrOperand IrOperand.h "IrOperand.h"
/// @brief IR(intermediate representation) のオペランドを表すクラス
//////////////////////////////////////////////////////////////////////
class IrOperand
{
public:

  /// @brief デストラクタ
  virtual
  ~IrOperand() { }


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief 変数型の時 true を返す．
  virtual
  bool
  is_variable() const = 0;

  /// @brief 配列型の時 true を返す．
  virtual
  bool
  is_array() const = 0;

  /// @brief 定数型の時 true を返す．
  virtual
  bool
  is_constant() const = 0;

  /// @brief 変数型/配列型の時の変数IDを返す．
  virtual
  int
  var_id() const = 0;

  /// @brief 配列型の時のインデックスを返す．
  virtual


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////


};

END_NAMESPACE_WARLOCK

#endif // IROPERAND_H
