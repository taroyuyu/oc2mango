//
//  SymbolStack.m
//  oc2mangoLib
//
//  Created by Jiang on 2019/5/23.
//  Copyright © 2019年 SilverFruity. All rights reserved.
//

#import "SymbolStack.h"

@implementation Symbol
- (instancetype)initWithName:(NSString *)name{
    self = [super init];
    self.name = name;
    return self;
}
+ (instancetype)symbolWithName:(NSString *)name{
    return [[[self class] alloc] initWithName:name];
}
@end

@implementation TypeSymbol


@end

@implementation VariableSymbol


@end

@implementation FuncSymbolTable
- (instancetype)init
{
    self = [super init];
    self.symbolTable = [NSMutableDictionary dictionary];
    return self;
}
- (Symbol *)lookup:(NSString *)name{
    return self.symbolTable[name];
}
- (void)addSymbol:(Symbol *)symbol forKey:(NSString *)key{
    self.symbolTable[key] = symbol;
}
@end

@implementation FuncSymbolStack
- (instancetype)init
{
    self = [super init];
    self.stack = [NSMutableArray array];
    [self push:[FuncSymbolTable new]];
    return self;
}
- (Symbol *)lookup:(NSString *)name{
    for (FuncSymbolTable *func in self.stack) {
        if ([func lookup:name]) {
            return [func lookup:name];
        }
    }
    return nil;
}
- (void)addSymbolToLast:(Symbol *)symbol forKey:(NSString *)key{
    [self.stack.lastObject addSymbol:symbol forKey:key];
}
- (void)push:(FuncSymbolTable *)funcSymbol{
    [self.stack addObject:funcSymbol];
}
- (void)pop{
    [self.stack removeLastObject];
}
@end
