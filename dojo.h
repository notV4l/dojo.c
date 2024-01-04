#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum BlockTag {
  BlockTagLatest,
  BlockTagPending,
} BlockTag;

typedef enum ComparisonOperator {
  ComparisonOperatorEq,
  ComparisonOperatorNeq,
  ComparisonOperatorGt,
  ComparisonOperatorGte,
  ComparisonOperatorLt,
  ComparisonOperatorLte,
} ComparisonOperator;

typedef enum LogicalOperator {
  LogicalOperatorAnd,
  LogicalOperatorOr,
} LogicalOperator;

typedef struct Account Account;

typedef struct CJsonRpcClient CJsonRpcClient;

typedef struct ToriiClient ToriiClient;

typedef struct Error {
  char *message;
} Error;

typedef enum ResultToriiClient_Tag {
  ResultToriiClientOkToriiClient,
  ResultToriiClientErrToriiClient,
} ResultToriiClient_Tag;

typedef struct ResultToriiClient {
  ResultToriiClient_Tag tag;
  union {
    struct {
      struct ToriiClient *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultToriiClient;

typedef struct CArrayc_char {
  const char **data;
  uintptr_t data_len;
} CArrayc_char;

typedef struct KeysClause {
  const char *model;
  struct CArrayc_char keys;
} KeysClause;

typedef struct FieldElement {
  uint8_t data[32];
} FieldElement;

typedef enum Primitive_Tag {
  PrimitiveU8,
  PrimitiveU16,
  PrimitiveU32,
  PrimitiveU64,
  PrimitiveU128,
  PrimitiveU256,
  PrimitiveU256,
  PrimitiveUSize,
  PrimitiveBool,
  PrimitiveFelt252,
  PrimitiveClassHash,
  PrimitiveContractAddress,
} Primitive_Tag;

typedef struct Primitive {
  Primitive_Tag tag;
  union {
    struct {
      uint8_t u8;
    };
    struct {
      uint16_t u16;
    };
    struct {
      uint32_t u32;
    };
    struct {
      uint64_t u64;
    };
    struct {
      uint8_t u128[16];
    };
    struct {
      uint64_t u256[4];
    };
    struct {
      uint32_t u256[8];
    };
    struct {
      uint32_t u_size;
    };
    struct {
      bool bool_;
    };
    struct {
      struct FieldElement felt252;
    };
    struct {
      struct FieldElement class_hash;
    };
    struct {
      struct FieldElement contract_address;
    };
  };
} Primitive;

typedef struct Member {
  const char *name;
  struct Ty *ty;
  bool key;
} Member;

typedef struct CArrayMember {
  struct Member *data;
  uintptr_t data_len;
} CArrayMember;

typedef struct Struct {
  const char *name;
  struct CArrayMember children;
} Struct;

typedef struct EnumOption {
  const char *name;
  struct Ty *ty;
} EnumOption;

typedef struct CArrayEnumOption {
  struct EnumOption *data;
  uintptr_t data_len;
} CArrayEnumOption;

typedef struct Enum {
  const char *name;
  uint8_t option;
  struct CArrayEnumOption options;
} Enum;

typedef struct CArrayTy {
  struct Ty *data;
  uintptr_t data_len;
} CArrayTy;

typedef enum Ty_Tag {
  TyPrimitive,
  TyStruct,
  TyEnum,
  TyTuple,
} Ty_Tag;

typedef struct Ty {
  Ty_Tag tag;
  union {
    struct {
      struct Primitive primitive;
    };
    struct {
      struct Struct struct_;
    };
    struct {
      struct Enum enum_;
    };
    struct {
      struct CArrayTy tuple;
    };
  };
} Ty;

typedef enum COptionTy_Tag {
  COptionTySomeTy,
  COptionTyNoneTy,
} COptionTy_Tag;

typedef struct COptionTy {
  COptionTy_Tag tag;
  union {
    struct {
      struct Ty *some;
    };
  };
} COptionTy;

typedef enum ResultCOptionTy_Tag {
  ResultCOptionTyOkCOptionTy,
  ResultCOptionTyErrCOptionTy,
} ResultCOptionTy_Tag;

typedef struct ResultCOptionTy {
  ResultCOptionTy_Tag tag;
  union {
    struct {
      struct COptionTy ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCOptionTy;

typedef struct Model {
  const char *name;
  struct CArrayMember members;
} Model;

typedef struct CArrayModel {
  struct Model *data;
  uintptr_t data_len;
} CArrayModel;

typedef struct Entity {
  struct FieldElement hashed_keys;
  struct CArrayModel models;
} Entity;

typedef struct CArrayEntity {
  struct Entity *data;
  uintptr_t data_len;
} CArrayEntity;

typedef enum ResultCArrayEntity_Tag {
  ResultCArrayEntityOkCArrayEntity,
  ResultCArrayEntityErrCArrayEntity,
} ResultCArrayEntity_Tag;

typedef struct ResultCArrayEntity {
  ResultCArrayEntity_Tag tag;
  union {
    struct {
      struct CArrayEntity ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCArrayEntity;

typedef struct CArrayu8 {
  uint8_t *data;
  uintptr_t data_len;
} CArrayu8;

typedef enum ValueType_Tag {
  ValueTypeString,
  ValueTypeInt,
  ValueTypeUInt,
  ValueTypeBool,
  ValueTypeBytes,
} ValueType_Tag;

typedef struct ValueType {
  ValueType_Tag tag;
  union {
    struct {
      const char *string;
    };
    struct {
      int64_t int_;
    };
    struct {
      uint64_t u_int;
    };
    struct {
      bool bool_;
    };
    struct {
      struct CArrayu8 bytes;
    };
  };
} ValueType;

typedef struct Value {
  struct Primitive primitive_type;
  struct ValueType value_type;
} Value;

typedef struct MemberClause {
  const char *model;
  const char *member;
  enum ComparisonOperator operator_;
  struct Value value;
} MemberClause;

typedef struct CArrayClause {
  struct Clause *data;
  uintptr_t data_len;
} CArrayClause;

typedef struct CompositeClause {
  const char *model;
  enum LogicalOperator operator_;
  struct CArrayClause clauses;
} CompositeClause;

typedef enum Clause_Tag {
  ClauseKeys,
  ClauseMember,
  ClauseComposite,
} Clause_Tag;

typedef struct Clause {
  Clause_Tag tag;
  union {
    struct {
      struct KeysClause keys;
    };
    struct {
      struct MemberClause member;
    };
    struct {
      struct CompositeClause composite;
    };
  };
} Clause;

typedef enum COptionClause_Tag {
  COptionClauseSomeClause,
  COptionClauseNoneClause,
} COptionClause_Tag;

typedef struct COptionClause {
  COptionClause_Tag tag;
  union {
    struct {
      struct Clause some;
    };
  };
} COptionClause;

typedef struct Query {
  uint32_t limit;
  uint32_t offset;
  struct COptionClause clause;
} Query;

typedef struct CArrayKeysClause {
  struct KeysClause *data;
  uintptr_t data_len;
} CArrayKeysClause;

typedef enum Resultbool_Tag {
  ResultboolOkbool,
  ResultboolErrbool,
} Resultbool_Tag;

typedef struct Resultbool {
  Resultbool_Tag tag;
  union {
    struct {
      bool ok;
    };
    struct {
      struct Error err;
    };
  };
} Resultbool;

typedef struct CArrayFieldElement {
  struct FieldElement *data;
  uintptr_t data_len;
} CArrayFieldElement;

typedef struct ModelMetadata {
  struct Ty schema;
  const char *name;
  uint32_t packed_size;
  uint32_t unpacked_size;
  struct FieldElement class_hash;
  struct CArrayFieldElement layout;
} ModelMetadata;

typedef struct CHashItemc_charModelMetadata {
  const char *key;
  struct ModelMetadata value;
} CHashItemc_charModelMetadata;

typedef struct CArrayCHashItemc_charModelMetadata {
  struct CHashItemc_charModelMetadata *data;
  uintptr_t data_len;
} CArrayCHashItemc_charModelMetadata;

typedef struct WorldMetadata {
  struct FieldElement world_address;
  struct FieldElement world_class_hash;
  struct FieldElement executor_address;
  struct FieldElement executor_class_hash;
  struct CArrayCHashItemc_charModelMetadata models;
} WorldMetadata;

typedef struct Signature {
  /**
   * The `r` value of a signature
   */
  struct FieldElement r;
  /**
   * The `s` value of a signature
   */
  struct FieldElement s;
} Signature;

typedef enum ResultSignature_Tag {
  ResultSignatureOkSignature,
  ResultSignatureErrSignature,
} ResultSignature_Tag;

typedef struct ResultSignature {
  ResultSignature_Tag tag;
  union {
    struct {
      struct Signature ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultSignature;

typedef enum ResultFieldElement_Tag {
  ResultFieldElementOkFieldElement,
  ResultFieldElementErrFieldElement,
} ResultFieldElement_Tag;

typedef struct ResultFieldElement {
  ResultFieldElement_Tag tag;
  union {
    struct {
      struct FieldElement ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultFieldElement;

typedef enum ResultCJsonRpcClient_Tag {
  ResultCJsonRpcClientOkCJsonRpcClient,
  ResultCJsonRpcClientErrCJsonRpcClient,
} ResultCJsonRpcClient_Tag;

typedef struct ResultCJsonRpcClient {
  ResultCJsonRpcClient_Tag tag;
  union {
    struct {
      struct CJsonRpcClient *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCJsonRpcClient;

typedef enum ResultAccount_Tag {
  ResultAccountOkAccount,
  ResultAccountErrAccount,
} ResultAccount_Tag;

typedef struct ResultAccount {
  ResultAccount_Tag tag;
  union {
    struct {
      struct Account *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultAccount;

/**
 * Block hash, number or tag
 */
typedef enum BlockId_Tag {
  BlockIdHash,
  BlockIdNumber,
  BlockIdBlockTag,
} BlockId_Tag;

typedef struct BlockId {
  BlockId_Tag tag;
  union {
    struct {
      struct FieldElement hash;
    };
    struct {
      uint64_t number;
    };
    struct {
      enum BlockTag block_tag;
    };
  };
} BlockId;

typedef struct Call {
  const char *to;
  const char *selector;
  struct CArrayFieldElement calldata;
} Call;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct ResultToriiClient client_new(const char *torii_url,
                                    const char *rpc_url,
                                    const char *world,
                                    const struct KeysClause *entities,
                                    uintptr_t entities_len);

struct ResultCOptionTy client_model(struct ToriiClient *client, const struct KeysClause *keys);

struct ResultCArrayEntity client_entities(struct ToriiClient *client, const struct Query *query);

struct CArrayKeysClause client_subscribed_models(struct ToriiClient *client);

struct Resultbool client_start_subscription(struct ToriiClient *client);

struct WorldMetadata client_metadata(struct ToriiClient *client);

struct Resultbool client_add_models_to_sync(struct ToriiClient *client,
                                            const struct KeysClause *models,
                                            uintptr_t models_len);

struct Resultbool client_on_sync_model_update(struct ToriiClient *client,
                                              struct KeysClause model,
                                              void (*callback)(void));

struct Resultbool client_on_entity_state_update(struct ToriiClient *client,
                                                struct FieldElement *entities,
                                                uintptr_t entities_len,
                                                void (*callback)(struct FieldElement,
                                                                 struct CArrayModel));

struct Resultbool client_remove_models_to_sync(struct ToriiClient *client,
                                               const struct KeysClause *models,
                                               uintptr_t models_len);

struct FieldElement signing_key_new(void);

struct ResultSignature signing_key_sign(struct FieldElement private_key, struct FieldElement hash);

struct ResultFieldElement felt_from_hex_be(const char *hex);

struct FieldElement verifying_key_new(struct FieldElement signing_key);

struct Resultbool verifying_key_verify(struct FieldElement verifying_key,
                                       struct FieldElement hash,
                                       struct Signature signature);

struct ResultCJsonRpcClient jsonrpc_client_new(const char *rpc_url);

struct ResultAccount account_new(struct CJsonRpcClient *rpc,
                                 struct FieldElement private_key,
                                 const char *address);

struct ResultAccount account_deploy_burner(struct CJsonRpcClient *rpc,
                                           struct Account *master_account);

struct FieldElement account_address(struct Account *account);

struct FieldElement account_chain_id(struct Account *account);

void account_set_block_id(struct Account *account, struct BlockId block_id);

struct ResultFieldElement account_execute_raw(struct Account *account,
                                              const struct Call *calldata,
                                              uintptr_t calldata_len);

struct Resultbool wait_for_transaction(struct CJsonRpcClient *rpc, struct FieldElement txn_hash);

struct FieldElement hash_get_contract_address(struct FieldElement class_hash,
                                              struct FieldElement salt,
                                              const struct FieldElement *constructor_calldata,
                                              uintptr_t constructor_calldata_len,
                                              struct FieldElement deployer_address);

void client_free(struct ToriiClient *t);

void jsonrpc_client_free(struct CJsonRpcClient *rpc);

void model_free(struct Model *model);

void account_free(struct Account *account);

void ty_free(struct Ty *ty);

void entity_free(struct Entity *entity);

void error_free(struct Error *error);

void world_metadata_free(struct WorldMetadata *metadata);

void carray_free(void *data, uintptr_t data_len);

void string_free(char *string);

extern void log(const str *s);

extern void error(const str *s);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
