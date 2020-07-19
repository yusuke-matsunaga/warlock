#ifndef FGNODE_H
#define FGNODE_H

/// @file FgNode.h
/// @brief FgNode のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2020 Yusuke Matsunaga
/// All rights reserved.


#include "warlock.h"


BEGIN_NAMESPACE_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class FgNode FgNode.h "FgNode.h"
/// @brief フローグラフのノードを表すクラス
//////////////////////////////////////////////////////////////////////
class FgNode
{
public:

  /// @brief コンストラクタ
  /// @param[in] id ID番号
  /// @param[in] fanin_list ファンインノードのリスト
  FgNode(int id,
	 const vector<FgNode*>& fanin_list);

  /// @brief デストラクタ
  virtual
  ~FgNode() = default;


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief ID番号を返す．
  int
  id() const;

  /// @brief ノードの種類を返す．
  virtual
  NodeType
  type() const = 0;

  /// @brief 名前を返す．
  virtual
  string
  name() const = 0;

  /// @brief 入力しているノードの数を返す．
  int
  input_num() const;

  /// @brief 入力しているノードを返す．
  /// @param[in] pos 位置番号 ( 0 <= pos < input_num() )
  FgNode*
  input(int pos) const;

  /// @brief 出力しているノードの数を返す．
  int
  output_num() const;

  /// @brief 出力しているノードを返す．
  /// @param[in] pos 位置番号 ( 0 <= pos < output_num() )
  FgNode*
  output(int pos) const;


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // ID番号
  int mId;

  // ファンインの枝のリスト
  vector<FgNode*> mFaninList;

  // ファンアウトの枝のリスト
  vector<FgNode*> mFanoutList;

};


//////////////////////////////////////////////////////////////////////
// インライン関数の定義
//////////////////////////////////////////////////////////////////////

// @brief コンストラクタ
// @param[in] id ID番号
// @param[in] fanin_list ファンインノードのリスト
inline
FgNode::FgNode(int id,
	       const vector<FgNode*>& fanin_list) :
  mId{id},
  mFaninList{fanin_list}
{
  for ( auto fanin: mFaninList ) {
    fanin->mFanoutList.push_back(this);
  }
}

// @brief ID番号を返す．
inline
int
FgNode::id() const
{
  return mId;
}

// @brief 入力しているノードの数を返す．
inline
int
FgNode::input_num() const
{
  return mFaninList.size();
}

// @brief 入力しているノードを返す．
// @param[in] pos 位置番号 ( 0 <= pos < input_num() )
inline
FgNode*
FgNode::input(int pos) const
{
  ASSERt_COND( 0 <= pos && pos < input_num() );
  return mFaninList[pos];
}

// @brief 出力しているノードの数を返す．
inline
int
FgNode::output_num() const
{
  return mFanoutList.size();
}

// @brief 出力しているノードを返す．
// @param[in] pos 位置番号 ( 0 <= pos < output_num() )
inline
FgNode*
FgNode::output(int pos) const
{
  ASSERT_COND( 0 <= pos && pos < output_num() );
  return mFanoutList[pos];
}

END_NAMESPACE_WARLOCK

#endif // FGNODE_H
