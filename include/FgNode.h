#ifndef FGNODE_H
#define FGNODE_H

/// @file FgNode.h
/// @brief FgNode のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2016 Yusuke Matsunaga
/// All rights reserved.


#include "warlock.h"


BEGIN_NAMESPACE_YM_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class FgNode FgNode.h "FgNode.h"
/// @brief フローグラフのノードを表すクラス
//////////////////////////////////////////////////////////////////////
class FgNode
{
public:

  /// @brief デストラクタ
  virtual
  ~FgNode() { }


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief ノードの種類を返す．
  virtual
  NodeType
  type() const = 0;

  /// @brief 入力している枝の数を返す．
  virtual
  ymuint
  input_num() const = 0;

  /// @brief 入力している枝を返す．
  /// @param[in] pos 位置番号 ( 0 <= pos < input_num() )
  virtual
  FgEdge*
  input(ymuint pos) const = 0;

  /// @brief 出力している枝の数を返す．
  virtual
  ymuint
  output_num() const = 0;

  /// @brief 出力している枝を返す．
  /// @param[in] pos 位置番号 ( 0 <= pos < output_num() )
  virtual
  FgEdge*
  output(ymuint pos) const = 0;


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////


};

END_NAMESPACE_YM_WARLOCK

#endif // FGNODE_H
