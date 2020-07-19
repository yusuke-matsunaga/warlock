#ifndef FLOWGRAPH_H
#define FLOWGRAPH_H

/// @file FlowGraph.h
/// @brief FlowGraph のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2020 Yusuke Matsunaga
/// All rights reserved.

#include "warlock.h"


BEGIN_NAMESPACE_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class FlowGraph FlowGraph.h "FlowGraph.h"
/// @brief Flow Graph を表すクラス
//////////////////////////////////////////////////////////////////////
class FlowGraph
{
public:

  /// @brief コンストラクタ
  FlowGraph();

  /// @brief デストラクタ
  ~FlowGraph();


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @grief 演算器タイプを登録する．
  /// @param[in] optype 演算器タイプ
  /// @return 演算器タイプ番号を返す．
  int
  reg_optype(const OpType& optype);

  /// @brief 演算ノードを追加する．
  /// @param[in] optype_id 演算器タイプ番号
  /// @param[in] fanin_list ファンインノードのリスト
  void
  add_opnode(int optype_id,
	     const vector<FgNode*>& fanin_list);

  /// @brief 演算器の種類の数を返す．
  int
  optype_num() const;

  /// @brief 演算器タイプを返す．
  /// @param[in] pos 位置番号 ( 0 <= pos < optype_num() )
  const OpType&
  optype(int pos) const;

  /// @brief 演算ノードのリストを返す．
  /// @param[in] pos 位置番号 ( 0 <= pos < optype_num() )
  const vector<FgNode*>&
  opnode_list(int pos) const;


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられるデータ構造
  //////////////////////////////////////////////////////////////////////

  struct OpTypeInfo {
    // タイプ番号
    int mTypeId;
    // 演算器タイプ
    const OpType* mOpType;
    // 演算ノードのリスト
    vector<OpNode*> mNodeList;
  };


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // 演算器タイプのリスト
  vector<OpTypeInfo> mOpTypeList;

};

END_NAMESPACE_WARLOCK

#endif // FLOWGRAPH_H
