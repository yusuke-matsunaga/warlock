#ifndef OPTYPE_H
#define OPTYPE_H

/// @file OpType.h
/// @brief OpType のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2020 Yusuke Matsunaga
/// All rights reserved.

#include "warlock.h"


BEGIN_NAMESPACE_WARLOCK

//////////////////////////////////////////////////////////////////////
/// @class OpType OpType.h "OpType.h"
/// @brief 演算器タイプを表すクラス
//////////////////////////////////////////////////////////////////////
class OpType
{
public:

  /// @brief コンストラクタ
  /// @param[in] name 名前
  /// @param[in] output_width 出力のビット幅
  /// @param[in] input_info_list 入力の情報のリスト
  ///
  /// input_info_list はビット幅と要素数のペアのリスト
  OpType(const string& name,
	 int output_width,
	 const vector<pair<int, int>>& input_info_list);

  /// @brief コンストラクタ
  /// @param[in] name 名前
  /// @param[in] output_width 出力のビット幅
  /// @param[in] input_width 入力のビット幅
  /// @param[in] input_num 入力の要素数
  ///
  /// 全ての入力が等価な場合
  OpType(const string& name,
	 int output_width,
	 int input_width,
	 int input_num);

  /// @brief デストラクタ
  ~OpType() = default;


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief 演算タイプ名を返す．
  string
  name() const;

  /// @brief 出力のビット幅を返す．
  int
  output_width() const;

  /// @brief 入力グループ数を返す．
  int
  input_group_num() const;

  /// @brief 入力のビット幅を返す．
  /// @param[in] grp_id グループ番号 ( 0 <= grp_id < input_group_num() )
  int
  input_width(int grp_id) const;

  /// @brief 入力グループの要素数を返す．
  /// @param[in] grp_id グループ番号 ( 0 <= grp_id < input_group_num() )
  int
  input_num(int grp_id) const;


private:
  //////////////////////////////////////////////////////////////////////
  // 内部で用いられる関数
  //////////////////////////////////////////////////////////////////////


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // 名前
  string mName;

  // 出力のビット幅
  int mOutputWidth;

  // 入力グループの情報
  vector<pair<int, int>> mInputInfoList;

};


//////////////////////////////////////////////////////////////////////
// インライン関数の定義
//////////////////////////////////////////////////////////////////////

// @brief コンストラクタ
// @param[in] name 名前
// @param[in] output_width 出力のビット幅
// @param[in] input_info_list 入力の情報のリスト
//
// input_info_list はビット幅と要素数のペアのリスト
inline
OpType::OpType(const string& name,
	       int output_width,
	       const vector<pair<int, int>>& input_info_list) :
  mName{name},
  mOuputWidth{output_width},
  mInputInfoList{input_inf_list}
{
}

// @brief コンストラクタ
// @param[in] name 名前
// @param[in] output_width 出力のビット幅
// @param[in] input_width 入力のビット幅
// @param[in] input_num 入力の要素数
//
// 全ての入力が等価な場合
inline
OpType::OpType(const string& name,
	       int output_width,
	       int input_width,
	       int input_num) :
  mName{name},
  mOutputWidth{output_width},
  mInputInfoList{{input_width, input_num}}
{
}

// @brief 演算タイプ名を返す．
inline
string
OpType::name() const
{
  return mName;
}

// @brief 出力のビット幅を返す．
inline
int
OpType::output_width() const
{
  return mOutputWidth;
}

// @brief 入力グループ数を返す．
inline
int
OpType::input_group_num() const
{
  return mInputInfoList.size();
}

// @brief 入力のビット幅を返す．
// @param[in] grp_id グループ番号 ( 0 <= grp_id < input_group_num() )
inline
int
OpType::input_width(int grp_id) const
{
  ASSERT_COND( 0 <= grp_id && grp_id < input_group_num() );
  return mInputInfoList[grp_id].first;
}

// @brief 入力グループの要素数を返す．
// @param[in] grp_id グループ番号 ( 0 <= grp_id < input_group_num() )
inline
int
OpType::input_num(int grp_id) const
{
  ASSERT_COND( 0 <= grp_id && grp_id < input_group_num() );
  return mInputInfoList[grp_id].second;
}

END_NAMESPACE_WARLOCK

#endif // OPTYPE_H
