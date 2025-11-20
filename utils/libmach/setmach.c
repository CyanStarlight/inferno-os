#include	<lib9.h>
#include	<bio.h>
#include	"mach.h"
		/* table for selecting machine-dependent parameters */

typedef	struct machtab Machtab;

struct machtab
{
	char		*name;			/* machine name */
	short		type;			/* executable type */
	short		boottype;		/* bootable type */
	int		asstype;		/* disassembler code */
	Mach		*mach;			/* machine description */
	Machdata	*machdata;		/* machine functions */
};

extern	Mach		mi386, mamd64,
			marm, mmips2be, mmips2le, mriscv, mriscv64;

extern	Machdata	sparcmach, i386mach,
			armmach, riscvmach, riscv64mach;

/*
 *	machine selection table.  machines with native disassemblers should
 *	follow the plan 9 variant in the table; native modes are selectable
 *	only by name.
 */
Machtab	machines[] =
{
	{	"mips2LE",			/*plan 9 mips2 little endian*/
		FMIPS2LE,
		0,
		AMIPS,
		0,
		0, 	},
	{	"mips",				/*plan 9 mips*/
		FMIPS,
		FMIPSB,
		AMIPS,
		0,
		0, 	},
	{	"mips2",			/*plan 9 mips2*/
		FMIPS2BE,
		FMIPSB,
		AMIPS,
		0,
		0, 	},		/* shares debuggers with native mips */
	{	"mipsco",			/*native mips - must follow plan 9*/
		FMIPS,
		FMIPSB,
		AMIPSCO,
		0,
		0,	},
	{	"sparc",			/*plan 9 sparc */
		FSPARC,
		FSPARCB,
		ASPARC,
		0,
		0,	},
	{	"sunsparc",			/*native sparc - must follow plan 9*/
		FSPARC,
		FSPARCB,
		ASUNSPARC,
		0,
		0,	},
	{	"386",				/*plan 9 386*/
		FI386,
		FI386B,
		AI386,
		&mi386,
		&i386mach,	},
	{	"86",				/*8086 - a peach of a machine*/
		FI386,
		FI386B,
		AI8086,
		&mi386,
		&i386mach,	},
	{	"amd64",			/*amd64*/
		FAMD64,
		FAMD64B,
		AAMD64,
		&mamd64,
		&i386mach,	},
	{	"arm",				/*ARM*/
		FARM,
		FARMB,
		AARM,
		&marm,
		&armmach,	},
	{	"power",			/*PowerPC*/
		FPOWER,
		FPOWERB,
		APOWER,
		0,
		0,	},
	{	"power64",			/*PowerPC*/
		FPOWER64,
		FPOWER64B,
		APOWER64,
		0,
		0,	},
	{	"riscv",
		FRISCV,
		FRISCVB,
		ARISCV,
		&mriscv,
		&riscvmach,	},
	{	"riscv64",
		FRISCV64,
		FRISCV64B,
		ARISCV64,
		&mriscv64,
		&riscv64mach,	},
	{	0		},		/*the terminator*/
};

/*
 *	select a machine by executable file type
 */
void
machbytype(int type)
{
	Machtab *mp;

	for (mp = machines; mp->name; mp++){
		if (mp->type == type || mp->boottype == type) {
			asstype = mp->asstype;
			if (mp->machdata)
				machdata = mp->machdata;
			if (mp->mach)
				mach = mp->mach;
			break;
		}
	}
}
/*
 *	select a machine by name
 */
int
machbyname(char *name)
{
	Machtab *mp;

	if (!name) {
		/* default to the primary supported target */
		asstype = AI386;
		machdata = &i386mach;
		mach = &mi386;
		return 1;
	}
	for (mp = machines; mp->name; mp++){
		if (strcmp(mp->name, name) == 0) {
			asstype = mp->asstype;
			machdata = mp->machdata;
			mach = mp->mach;
			return 1;
		}
	}
	return 0;
}
