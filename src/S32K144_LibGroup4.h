#ifndef S32K144_LIBGROUP4_H_
#define S32K144_LIBGROUP4_H_

//Library for Initializing Port
#define PCC_base 0x40065000u

#define PCC_PortD (*(volatile unsigned int*) (PCC_base + 0x130u))
#define PCC_PortC (*(volatile unsigned int*) (PCC_base + 0x12Cu))
#define PCC_LPIT (*(volatile unsigned int*) (PCC_base + 0xDCu))
#define PCC_UART1 (*(volatile unsigned int*) (PCC_base + 0x1ACu))
#define PCC_FTM0 (*(volatile unsigned int*) (PCC_base + 0xE0u))

#define PCR_PortD 0x4004C000u
#define PCR_PortC 0x4004B000u

typedef struct PCR {
	volatile unsigned int PCR[32];
} PCR_typedef;
#define PortD ((PCR_typedef*)PCR_PortD)
#define PortC ((PCR_typedef*)PCR_PortC)

#define GPIO_D_base 0x400FF0C0u
#define GPIO_C_base 0x400FF080u
typedef struct GPIO {
	volatile unsigned int PDOR;
	volatile unsigned int PSOR;
	volatile unsigned int PCOR;
	volatile unsigned int PTOR;
	volatile unsigned int PDIR;
	volatile unsigned int PDDR;
	volatile unsigned int PIDR;
} GPIO_typedef;
#define GPIO_D ((GPIO_typedef*)GPIO_D_base)
#define GPIO_C ((GPIO_typedef*)GPIO_C_base)

//Library for Initializing SOSC
#define SCG_base 0x40064000u

typedef struct {
  volatile const  unsigned long int VERID;
  volatile const  unsigned long int PARAM;
       unsigned char RESERVED_0[8];
  volatile const  unsigned long int CSR;
  volatile unsigned long int RCCR;
  volatile unsigned long int VCCR;
  volatile unsigned long int HCCR;
  volatile unsigned long int CLKOUTCNFG;
       unsigned char RESERVED_1[220];
  volatile unsigned long int SOSCCSR;
  volatile unsigned long int SOSCDIV;
  volatile unsigned long int SOSCCFG;
       unsigned char RESERVED_2[244];
  volatile unsigned long int SIRCCSR;
  volatile unsigned long int SIRCDIV;
  volatile unsigned long int SIRCCFG;
       unsigned char RESERVED_3[244];
  volatile unsigned long int FIRCCSR;
  volatile unsigned long int FIRCDIV;
  volatile unsigned long int FIRCCFG;
       unsigned char RESERVED_4[756];
  volatile unsigned long int SPLLCSR;
  volatile unsigned long int SPLLDIV;
  volatile unsigned long int SPLLCFG;
} SCG_Type;

#define SCG ((SCG_Type*)SCG_base)

//Library for Initializing SIM
#define SIM_base 0x40048000u
#define SIM_CHIPCTL (*(volatile unsigned int*) (SIM_base + 0x4u))

//Library for LPIT
/** LPIT - Register Layout Typedef */
#define LPIT_base 0x40037000u

typedef struct {
  volatile  unsigned int VERID;
  volatile  unsigned int PARAM;
  volatile unsigned int MCR;
  volatile unsigned int MSR;
  volatile unsigned int MIER;
  volatile unsigned int SETTEN;
  volatile unsigned int CLRTEN;
  	  unsigned char RESERVED_0[4];
  struct {
    volatile unsigned int TVAL;
    volatile  unsigned int CVAL;
    volatile unsigned int TCTRL;
    unsigned char RESERVED_0[4];
  } TMR[4];
} LPIT_Type;

#define LPIT ((LPIT_Type*)LPIT_base)

#define NVIC_base 0xE000E100
typedef struct {
  volatile unsigned int ISER[8];
	   unsigned char RESERVED_0[96];
  volatile unsigned int ICER[8];
	   unsigned char RESERVED_1[96];
  volatile unsigned int ISPR[8];
	   unsigned char RESERVED_2[96];
  volatile unsigned int ICPR[8];
	   unsigned char RESERVED_3[96];
  volatile unsigned int IABR[8];
	   unsigned char RESERVED_4[224];
  volatile unsigned char IP[240];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
	   unsigned char RESERVED_5[2576];
  volatile  unsigned int STIR;
} S32_NVIC_Type;

#define NVIC ((S32_NVIC_Type*)NVIC_base)

/*UART library*/
#define LPUART0_base  0x4006A000u
#define LPUART1_base  0x4006B000u
#define LPUART2_base  0x4006C000u

typedef struct {
	volatile const unsigned int VERID;
	volatile const unsigned int PARAM;
	volatile unsigned int GLOBAL;
	volatile unsigned int PINCFG;
	volatile unsigned int BAUD;
	volatile unsigned int STAT;
	volatile unsigned int CTRL;
	volatile unsigned int DATA;
	volatile unsigned int MATCH;
	volatile unsigned int MODIR;
	volatile unsigned int FIFO;
	volatile unsigned int WATER;
} LPUART_Type;

#define LPUART0                                  ((LPUART_Type *)LPUART0_base)
#define LPUART1                                  ((LPUART_Type *)LPUART1_base)
#define LPUART2                                  ((LPUART_Type *)LPUART2_base)


/** FTM - Register Layout Typedef */
typedef struct {
  volatile unsigned int SC;
  volatile unsigned int CNT;
  volatile unsigned int MOD;
  struct {
    volatile unsigned int CnSC;
    volatile unsigned int CnV;
  } CONTROLS[8];
  volatile unsigned int CNTIN;
  volatile unsigned int STATUS;
  volatile unsigned int MODE;
  volatile unsigned int SYNC;
  volatile unsigned int OUTINIT;
  volatile unsigned int OUTMASK;
  volatile unsigned int COMBINE;
  volatile unsigned int DEADTIME;
  volatile unsigned int EXTTRIG;
  volatile unsigned int POL;
  volatile unsigned int FMS;
  volatile unsigned int FILTER;
  volatile unsigned int FLTCTRL;
  volatile unsigned int QDCTRL;
  volatile unsigned int CONF;
  volatile unsigned int FLTPOL;
  volatile unsigned int SYNCONF;
  volatile unsigned int INVCTRL;
  volatile unsigned int SWOCTRL;
  volatile unsigned int PWMLOAD;
  volatile unsigned int HCR;
  volatile unsigned int PAIR0DEADTIME;
       unsigned char RESERVED_0[4];
  volatile unsigned int PAIR1DEADTIME;
       unsigned char RESERVED_1[4];
  volatile unsigned int PAIR2DEADTIME;
       unsigned char RESERVED_2[4];
  volatile unsigned int PAIR3DEADTIME;
} FTM_Type;

/** Peripheral FTM0 base address */
#define FTM0_BASE                                (0x40038000u)
/** Peripheral FTM0 base pointer */
#define FTM0                                     ((FTM_Type *)FTM0_BASE)
/** Peripheral FTM1 base address */
#define FTM1_BASE                                (0x40039000u)
/** Peripheral FTM1 base pointer */
#define FTM1                                     ((FTM_Type *)FTM1_BASE)
/** Peripheral FTM2 base address */
#define FTM2_BASE                                (0x4003A000u)
/** Peripheral FTM2 base pointer */
#define FTM2                                     ((FTM_Type *)FTM2_BASE)
/** Peripheral FTM3 base address */
#define FTM3_BASE                                (0x40026000u)
/** Peripheral FTM3 base pointer */
#define FTM3                                     ((FTM_Type *)FTM3_BASE)

#define portA 0
#define portB 1
#define portC 2
#define portD 3
#define portE 4

#define input  0
#define output 1


/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
void PORT_init(void);
void FTM0_init(void);
void SOSC_init(void);
void LPUART1_init(void);
void LPUART1_transmit(char send);
void NVIC_init(void);
void changeDutyCycle(void);
void changeFrequency(void);

#endif /* S32K144_LIBGROUP4_H_ */
