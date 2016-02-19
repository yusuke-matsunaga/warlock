#ifndef WARLOCK_H
#define WARLOCK_H

/// @file warlock.h
/// @brief warlock 用の名前空間の定義
///
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2016 Yusuke Matsunaga
/// All rights reserved.

#include "ym_config.h"
#include "version_config.h"


// 名前空間の定義ファイル
// 必ず先頭でインクルードしなければならない．

//////////////////////////////////////////////////////////////////////
// 名前空間の定義用マクロ
// namespace でネストするのがいやなので define マクロでごまかす．
//////////////////////////////////////////////////////////////////////

#define BEGIN_NAMESPACE_YM_WARLOCK \
BEGIN_NAMESPACE_YM \
BEGIN_NAMESPACE(nsWarlock)

#define END_NAMESPACE_YM_WARLOCK \
END_NAMESPACE(nsWarlock) \
END_NAMESPACE_YM


BEGIN_NAMESPACE_YM_WARLOCK


//////////////////////////////////////////////////////////////////////
// FgNode の種類を表す列挙型
//////////////////////////////////////////////////////////////////////
enum NodeType {
  kNode_START,
  kNode_END,
  kNODE_BRANCH,
  kNODE_JOIN,
  kNODE_CALL,

  kNODE_NOT,
  kNODE_AND,
  kNODE_OR,
  kNODE_XOR,

  kNODE_ADD,
  kNODE_SUB,
  kNODE_MUL,
  kNODE_DIV,
  kNODE_MOD,

  kNODE_BITSELECT,
  kNODE_PARTSELECT,

  kNODE_LOAD,
  kNODE_STORE,
};


//////////////////////////////////////////////////////////////////////
// クラス名の宣言
//////////////////////////////////////////////////////////////////////

class FgEdge;
class FgNode;
class FgGraph;

END_NAMESPACE_YM_WARLOCK

#endif // WARLOCK_H
