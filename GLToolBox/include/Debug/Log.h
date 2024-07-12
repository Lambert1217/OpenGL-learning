/**
 * @file Log.h
 * @author Lambert1217 (1904310303@qq.com)
 * @brief 日志系统
 * @date 2024-07-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

namespace GLToolBox
{

	class Log
	{
	public:
		// 日志系统初始化
		static void init();

		// 内联函数将直接在函数被调用处替换成函数体，避免了函数调用时的栈帧创建和销毁
		inline static std::shared_ptr<spdlog::logger> &GetLogger()
		{
			return s_Logger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

} // namespace GLToolBox

// 引擎 logger 宏
#define LOG_TRACE(...) ::GLToolBox::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::GLToolBox::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::GLToolBox::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::GLToolBox::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::GLToolBox::Log::GetLogger()->fatal(__VA_ARGS__)

// 断言
#define LOG_ASSERT(x, ...)                                   \
	{                                                        \
		if (!(x))                                            \
		{                                                    \
			LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			__debugbreak();                                  \
		}                                                    \
	}
