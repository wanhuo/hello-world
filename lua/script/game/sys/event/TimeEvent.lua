--
-- Author: xd
-- Date: 2015-12-08 20:26:43

--

local TimeEvent = {}

TimeEvent.TIMEEVENT_ONSP = "TIMEEVENT_ONSP"  				--体力恢复间隔到了

TimeEvent.TIMEEVENT_CDSHOP_1 = "TIMEEVENT_CDSHOP_1" 		--商城1的刷新时间
TimeEvent.TIMEEVENT_CDSHOP_2 = "TIMEEVENT_CDSHOP_2" 		--商城2的刷新时间
TimeEvent.TIMEEVENT_CDSHOP_3 = "TIMEEVENT_CDSHOP_3" 		--商城3的刷新时间
TimeEvent.TIMEEVENT_CDSHOP_4 = "TIMEEVENT_CDSHOP_4" 		--熔炼灵宝阁刷新时间

TimeEvent.TIMEEVENT_TOKEN_LOTTERY_CD = "TIMEEVENT_TOKEN_LOTTERY_CD" 	--抽卡系统，令牌抽卡cd
TimeEvent.TIMEEVENT_GOLD_LOTTERY_CD = "TIMEEVENT_GOLD_LOTTERY_CD" 		--抽卡系统，钻石抽卡cd

TimeEvent.TIMEEVENT_PVP_SHOP_REFRESH_CD = "TIMEEVENT_PVP_SHOP_REFRESH_CD"
TimeEvent.TIMEEVENT_PVP_FAST_REFRESH_CD = "TIMEEVENT_PVP_FAST_REFRESH_CD"

TimeEvent.TIMEEVENT_CHAR_SHOP_REFRESH_CD = "TIMEEVENT_CHAR_SHOP_REFRESH_CD"
--到达了某个固定时间
TimeEvent.TIMEEVENT_STATIC_CLOCK_REACH_EVENT = "TIMEEVENT_STATIC_CLOCK_REACH_EVENT"

--伙伴系统,技能点回复时间
TimeEvent.TIMEEVENT_PARTNER_SKILL_POINT_RESUME_EVENT = "TIMEEVENT_PARTNER_SKILL_POINT_RESUME_EVENT"
return TimeEvent