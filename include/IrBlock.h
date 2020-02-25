#ifndef IRBLOCK_H
#define IRBLOCK_H

/// @file IrBlock.h
/// @brief IrBlock のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2020 Yusuke Matsunaga
/// All rights reserved.


#include "warlock.h"


BEGIN_NAMESPACE_YM_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class IrBlock IrBlock.h "IrBlock.h"
/// @brief IR(intermediate representation) Block を表すクラス
///
/// IR Block はひとつの開始ノードと複数の終了(Jump)ノードを持つ．
//////////////////////////////////////////////////////////////////////
class IrBlock
{
public:

  /// @brief コンストラクタ
  IrBlock();

  /// @brief デストラクタ
  ~IrBlock();


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief ノード数を得る．
  int
  node_num() const;

  /// @brief ノードを返す．
  /// @param[in] pos 位置 ( 0 <= pos < node_num() )
  const IrNode*
  node(int pos) const;

  /// @brief 開始ノードを返す．
  ///
  /// 実は常に node(0) と等しい
  const IrNode*
  start_node() const;

  /// @brief 終了ノードの個数を返す．
  int
  end_node_num() const;

  /// @brief 終了ノードを返す．
  /// @param[in] pos 位置 ( 0 <= pos < end_node_num() )
  const IrNode*
  end_node(int pos) const;


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // ノードの配列
  vector<IrNode*> mNodeList;

  // 終了ノードの配列
  vector<IrNode*> mEndNodeList;

};

END_NAMESPACE_YM_WARLOCK

#endif // IRBLOCK_H
