/**
 * @file Log.cpp
 * @author Lambert1217 (1904310303@qq.com)
 * @brief 日志系统
 * @date 2024-07-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Debug/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace GLToolBox
{

	// 静态变量在类外部定义
	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::init()
	{
		// 设置日志输出格式
		spdlog::set_pattern("[%T] %^[%l]%$: %v");

		// 设置logger的名称和等级
		s_Logger = spdlog::stdout_color_mt("GLToolBox");
		s_Logger->set_level(spdlog::level::trace);

		LOG_INFO("日志初始化");
	}
} // namespace Lambix
