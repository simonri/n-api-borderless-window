#include <napi.h>
#include <iostream>
#include <windows.h>

namespace functionexample {
  std::string hello();
  Napi::String HelloWrapped(const Napi::CallbackInfo& info);

  Napi::Object Init(Napi::Env env, Napi::Object exports);
}

std::string functionexample::hello() {
  std::cout << "Hello World!\n";


  LPCTSTR windowName = L"Minecraft 1.8.9";
  auto hwnd = FindWindow(nullptr, windowName);

  std::cout << hwnd;

  return "Hello World";
}

Napi::String functionexample::HelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, functionexample::hello());
    return returnValue;
}

Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports) {
  exports.Set("hello", Napi::Function::New(env, functionexample::HelloWrapped));
  return exports;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return functionexample::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)