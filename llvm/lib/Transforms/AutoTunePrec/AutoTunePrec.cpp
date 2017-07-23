//===- AutoTunePrec.cpp - Tunes the function for better performance and lower precision with error threshold" ---------------===//
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;
 
#define DEBUG_TYPE "AutoTunePrec"


namespace {
  struct AutoTunePrec : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    AutoTunePrec() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }
  };
  char AutoTunePrec::ID = 0;
  RegisterPass<Hello> X("hello", "Hello World Pass");
}

