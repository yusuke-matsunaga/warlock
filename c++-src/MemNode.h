#ifndef MEMNODE_H
#define MEMNODE_H

/// @file MemNode.h
/// @brief MemNode のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2020 Yusuke Matsunaga
/// All rights reserved.

#include "FgNode.h"


BEGIN_NAMESPACE_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class MemNode MemNode.h "MemNode.h"
/// @brief メモリアクセスを行うノード
//////////////////////////////////////////////////////////////////////
class MemNode :
  public FgNode
{
public:

  /// @brief コンストラクタ
  /// @param[in] id ID番号
  /// @param[in] addr アドレス
  /// @param[in] block_id ブロック番号
  /// @param[in] bank_id バンク番号
  /// @param[in] offset オフセット
  MemNode(int id,
	  int addr,
	  int block_id,
	  int bank_id,
	  int offset);

  /// @brief デストラクタ
  ~MemNode();


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief アドレスを返す．
  int
  address() const;

  /// @brief ブロック番号を返す．
  int
  block_id() const;

  /// @brief バンク番号を返す．
  int
  bank_id() const;

  /// @brief オフセットを返す．
  int
  offset() const;


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // アドレス
  int mAddr;

  // ブロック番号
  int mBlock;

  // バンク番号
  int mBank;

  // オフセット
  int mOffset;

};


//////////////////////////////////////////////////////////////////////
// インライン関数の定義
//////////////////////////////////////////////////////////////////////

// @brief アドレスを返す．
inline
int
MemNode::address() const
{
  return mAddr;
}

// @brief ブロック番号を返す．
inline
int
MemNode::block_id() const
{
  return mBlock;
}

// @brief バンク番号を返す．
inline
int
MemNode::bank_id() const
{
  return mBank;
}

// @brief オフセットを返す．
inline
int
MemNode::offset() const
{
  return mOffset;
}

END_NAMESPACE_WARLOCK

#endif // MEMNODE_H
