#include "RE/ExtraCount.h"

#include "skse64/GameExtraData.h"  // s_ExtraCountVtbl
namespace RE
{
	ExtraCount::ExtraCount() :
		count(0),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraCountVtbl.GetUIntPtr();
	}


	ExtraCount::ExtraCount(SInt32 a_count) :
		count(a_count),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraCountVtbl.GetUIntPtr();
	}


	ExtraCount::~ExtraCount()
	{}


	ExtraDataType ExtraCount::GetType() const
	{
		return ExtraDataType::kCount;
	}


	bool ExtraCount::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraCount*>(a_rhs);
		return count != rhs->count;
	}
}