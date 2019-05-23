//
//  MakeDeclare.h
//  oc2mango
//
//  Created by Jiang on 2019/4/21.
//  Copyright © 2019年 SilverFruity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Parser.h"
#import "OCValue.h"
#import "Statement.h"



extern TypeSpecial *makeTypeSpecial(SpecialType type, NSString *name);
extern TypeSpecial *makeTypeSpecial(SpecialType type) __attribute__((overloadable)) ;

extern VariableDeclare *makeVariableDeclare(TypeSpecial *type, NSString *name);

extern MethodDeclare *makeMethodDeclare(BOOL isClassMethod, TypeSpecial *returnType);
extern MethodImplementation *makeMethodImplementation(MethodDeclare *declare);
extern FuncDeclare *makeFuncDeclare(TypeSpecial *returnType,NSMutableArray *vars);
extern FunctionImp *makeFuncImp(void);
extern id <OCMethodElement> makeMethodCallElement(OCMethodCallType type);

extern OCValue *makeValue(OC_VALUE_TYPE type, id value);
extern OCValue *makeValue(OC_VALUE_TYPE type) __attribute__((overloadable)) ;

extern UnaryExpression *makeUnaryExpression(UnaryOperatorType type);
extern BinaryExpression *makeBinaryExpression(BinaryOperatorType type);
extern TernaryExpression *makeTernaryExpression(void);
extern AssignExpression *makeAssignExpression(AssignOperatorType type);
extern DeclareExpression *makeDeclareExpression(VariableDeclare *declare);


extern IfStatement *makeIfStatement(id <Expression>judgement, FunctionImp *imp);
extern WhileStatement *makeWhileStatement(id <Expression>judgement, FunctionImp *imp);
extern DoWhileStatement *makeDoWhileStatement(id <Expression>judgement, FunctionImp *imp);
extern CaseStatement *makeCaseStatement(OCValue *value);
extern SwitchStatement *makeSwitchStatement(OCValue *value);
extern ForStatement *makeForStatement(FunctionImp *imp);
extern ForInStatement *makeForInStatement(FunctionImp *imp);

extern ReturnStatement *makeReturnStatement(id <ValueExpression> expression);
extern BreakStatement *makeBreakStatement(void);
extern ContinueStatement *makeContinueStatement(void);



extern void pushFuncSymbolTable(void);
extern void popFuncSymbolTable(void);
extern Symbol *lookupSymbol(NSString *name);
extern void addVariableSymbol(NSString *name);
extern void addTypeSymbol(NSString *name);
