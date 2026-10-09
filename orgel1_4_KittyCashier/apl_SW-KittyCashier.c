//ｷﾃｨｷｬｯｼｬｰのマイコン換装用にｶｽﾀﾏｲｽﾞしたｱﾌﾟﾘｹｰｼｮﾝ


//==============================================
//構成情報(個別ｱﾌﾟﾘｹｰｼｮﾝだけで使うもの)
//==============================================
#define	SLEEP_TMR	1000			//Sleepに入る前の時限[ms]
						//　操作の評価時間よりも長くすること


#ifdef SW_EN				//SWを実装するとき
//==============================================
//SW構成の定義
//==============================================
#define	SW_MODE	0x80			//ﾓｰﾄﾞ設定ﾏｽｸ
#define	SW_POL	0x40			//極性設定ﾏｽｸ
static const struct SW_CNF
{
	GPIO_TypeDef *gpio;		//GPIOｱﾄﾞﾚｽ
	unsigned short msk;		//ﾋﾞｯﾄﾏｽｸ
	unsigned char mode;		//b7:ﾓｰﾄﾞ(0=ﾘｱﾙﾓｰﾄﾞ､1=ﾀｲﾏｰﾓｰﾄﾞ)
					//b6:入力極性(0=負論理､1=正論理)
}sw_cnf[]=
{

//SW0の構成-------------------------------------
#ifdef SW0_BIT				//SW0を実装するとき
#ifdef SW0_TIMER
#define SW0_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW0_REAL
#define SW0_MODE 0x00
#define SW_REAL
#endif
#ifdef SW0_INV
#define SW0_POL 0x00
#else
#define SW0_POL SW_POL
#endif
	{SW0_GPIO,1<<SW0_BIT,SW0_MODE|SW0_POL},
#if SW0_BIT<4
#define SW0_EXTICR1	(SW0_EXTI_PORT<<SW0_BIT*8)
#define SW0_EXTICR2	0x00000000
#define SW0_EXTICR3	0x00000000
#define SW0_EXTICR4	0x00000000
#elif SW0_BIT<8
#define SW0_EXTICR1	0x00000000
#define SW0_EXTICR2	(SW0_EXTI_PORT<<(SW0_BIT-4)*8)
#define SW0_EXTICR3	0x00000000
#define SW0_EXTICR4	0x00000000
#elif SW0_BIT<12
#define SW0_EXTICR1	0x00000000
#define SW0_EXTICR2	0x00000000
#define SW0_EXTICR3	(SW0_EXTI_PORT<<(SW0_BIT-8)*8)
#define SW0_EXTICR4	0x00000000
#else
#define SW0_EXTICR1	0x00000000
#define SW0_EXTICR2	0x00000000
#define SW0_EXTICR3	0x00000000
#define SW0_EXTICR4	(SW0_EXTI_PORT<<(SW0_BIT-12)*8)
#endif
#define SW0_EXTIMSK	(1<<SW0_BIT)
#else					//SW0を実装しないとき
#define SW0_EXTICR1	0x00000000
#define SW0_EXTICR2	0x00000000
#define SW0_EXTICR3	0x00000000
#define SW0_EXTICR4	0x00000000
#define SW0_EXTIMSK	0x00000000
#endif

//SW1の構成-------------------------------------
#ifdef SW1_BIT				//SW1を実装するとき
#ifdef SW1_TIMER
#define SW1_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW1_REAL
#define SW1_MODE 0x00
#define SW_REAL
#endif
#ifdef SW1_INV
#define SW1_POL 0x00
#else
#define SW1_POL SW_POL
#endif
	{SW1_GPIO,1<<SW1_BIT,SW1_MODE|SW1_POL},
#if SW1_BIT<4
#define SW1_EXTICR1	(SW1_EXTI_PORT<<SW1_BIT*8)
#define SW1_EXTICR2	0x00000000
#define SW1_EXTICR3	0x00000000
#define SW1_EXTICR4	0x00000000
#elif SW1_BIT<8
#define SW1_EXTICR1	0x00000000
#define SW1_EXTICR2	(SW1_EXTI_PORT<<(SW1_BIT-4)*8)
#define SW1_EXTICR3	0x00000000
#define SW1_EXTICR4	0x00000000
#elif SW1_BIT<12
#define SW1_EXTICR1	0x00000000
#define SW1_EXTICR2	0x00000000
#define SW1_EXTICR3	(SW1_EXTI_PORT<<(SW1_BIT-8)*8)
#define SW1_EXTICR4	0x00000000
#else
#define SW1_EXTICR1	0x00000000
#define SW1_EXTICR2	0x00000000
#define SW1_EXTICR3	0x00000000
#define SW1_EXTICR4	(SW1_EXTI_PORT<<(SW1_BIT-12)*8)
#endif
#define SW1_EXTIMSK	(1<<SW1_BIT)
#else					//SW1を実装しないとき
#define SW1_EXTICR1	0x00000000
#define SW1_EXTICR2	0x00000000
#define SW1_EXTICR3	0x00000000
#define SW1_EXTICR4	0x00000000
#define SW1_EXTIMSK	0x00000000
#endif

//SW2の構成-------------------------------------
#ifdef SW2_BIT				//SW2を実装するとき
#ifdef SW2_TIMER
#define SW2_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW2_REAL
#define SW2_MODE 0x00
#define SW_REAL
#endif
#ifdef SW2_INV
#define SW2_POL 0x00
#else
#define SW2_POL SW_POL
#endif
	{SW2_GPIO,1<<SW2_BIT,SW2_MODE|SW2_POL},
#if SW2_BIT<4
#define SW2_EXTICR1	(SW2_EXTI_PORT<<SW2_BIT*8)
#define SW2_EXTICR2	0x00000000
#define SW2_EXTICR3	0x00000000
#define SW2_EXTICR4	0x00000000
#elif SW2_BIT<8
#define SW2_EXTICR1	0x00000000
#define SW2_EXTICR2	(SW2_EXTI_PORT<<(SW2_BIT-4)*8)
#define SW2_EXTICR3	0x00000000
#define SW2_EXTICR4	0x00000000
#elif SW2_BIT<12
#define SW2_EXTICR1	0x00000000
#define SW2_EXTICR2	0x00000000
#define SW2_EXTICR3	(SW2_EXTI_PORT<<(SW2_BIT-8)*8)
#define SW2_EXTICR4	0x00000000
#else
#define SW2_EXTICR1	0x00000000
#define SW2_EXTICR2	0x00000000
#define SW2_EXTICR3	0x00000000
#define SW2_EXTICR4	(SW2_EXTI_PORT<<(SW2_BIT-12)*8)
#endif
#define SW2_EXTIMSK	(1<<SW2_BIT)
#else					//SW2を実装しないとき
#define SW2_EXTICR1	0x00000000
#define SW2_EXTICR2	0x00000000
#define SW2_EXTICR3	0x00000000
#define SW2_EXTICR4	0x00000000
#define SW2_EXTIMSK	0x00000000
#endif

//SW3の構成-------------------------------------
#ifdef SW3_BIT				//SW3を実装するとき
#ifdef SW3_TIMER
#define SW3_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW3_REAL
#define SW3_MODE 0x00
#define SW_REAL
#endif
#ifdef SW3_INV
#define SW3_POL 0x00
#else
#define SW3_POL SW_POL
#endif
	{SW3_GPIO,1<<SW3_BIT,SW3_MODE|SW3_POL},
#if SW3_BIT<4
#define SW3_EXTICR1	(SW3_EXTI_PORT<<SW3_BIT*8)
#define SW3_EXTICR2	0x00000000
#define SW3_EXTICR3	0x00000000
#define SW3_EXTICR4	0x00000000
#elif SW3_BIT<8
#define SW3_EXTICR1	0x00000000
#define SW3_EXTICR2	(SW3_EXTI_PORT<<(SW3_BIT-4)*8)
#define SW3_EXTICR3	0x00000000
#define SW3_EXTICR4	0x00000000
#elif SW3_BIT<12
#define SW3_EXTICR1	0x00000000
#define SW3_EXTICR2	0x00000000
#define SW3_EXTICR3	(SW3_EXTI_PORT<<(SW3_BIT-8)*8)
#define SW3_EXTICR4	0x00000000
#else
#define SW3_EXTICR1	0x00000000
#define SW3_EXTICR2	0x00000000
#define SW3_EXTICR3	0x00000000
#define SW3_EXTICR4	(SW3_EXTI_PORT<<(SW3_BIT-12)*8)
#endif
#define SW3_EXTIMSK	(1<<SW3_BIT)
#else					//SW3を実装しないとき
#define SW3_EXTICR1	0x00000000
#define SW3_EXTICR2	0x00000000
#define SW3_EXTICR3	0x00000000
#define SW3_EXTICR4	0x00000000
#define SW3_EXTIMSK	0x00000000
#endif

//SW4の構成-------------------------------------
#ifdef SW4_BIT				//SW4を実装するとき
#ifdef SW4_TIMER
#define SW4_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW4_REAL
#define SW4_MODE 0x00
#define SW_REAL
#endif
#ifdef SW4_INV
#define SW4_POL 0x00
#else
#define SW4_POL SW_POL
#endif
	{SW4_GPIO,1<<SW4_BIT,SW4_MODE|SW4_POL},
#if SW4_BIT<4
#define SW4_EXTICR1	(SW4_EXTI_PORT<<SW4_BIT*8)
#define SW4_EXTICR2	0x00000000
#define SW4_EXTICR3	0x00000000
#define SW4_EXTICR4	0x00000000
#elif SW4_BIT<8
#define SW4_EXTICR1	0x00000000
#define SW4_EXTICR2	(SW4_EXTI_PORT<<(SW4_BIT-4)*8)
#define SW4_EXTICR3	0x00000000
#define SW4_EXTICR4	0x00000000
#elif SW4_BIT<12
#define SW4_EXTICR1	0x00000000
#define SW4_EXTICR2	0x00000000
#define SW4_EXTICR3	(SW4_EXTI_PORT<<(SW4_BIT-8)*8)
#define SW4_EXTICR4	0x00000000
#else
#define SW4_EXTICR1	0x00000000
#define SW4_EXTICR2	0x00000000
#define SW4_EXTICR3	0x00000000
#define SW4_EXTICR4	(SW4_EXTI_PORT<<(SW4_BIT-12)*8)
#endif
#define SW4_EXTIMSK	(1<<SW4_BIT)
#else					//SW4を実装しないとき
#define SW4_EXTICR1	0x00000000
#define SW4_EXTICR2	0x00000000
#define SW4_EXTICR3	0x00000000
#define SW4_EXTICR4	0x00000000
#define SW4_EXTIMSK	0x00000000
#endif

//SW5の構成-------------------------------------
#ifdef SW5_BIT				//SW5を実装するとき
#ifdef SW5_TIMER
#define SW5_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW5_REAL
#define SW5_MODE 0x00
#define SW_REAL
#endif
#ifdef SW5_INV
#define SW5_POL 0x00
#else
#define SW5_POL SW_POL
#endif
	{SW5_GPIO,1<<SW5_BIT,SW5_MODE|SW5_POL},
#if SW5_BIT<4
#define SW5_EXTICR1	(SW5_EXTI_PORT<<SW5_BIT*8)
#define SW5_EXTICR2	0x00000000
#define SW5_EXTICR3	0x00000000
#define SW5_EXTICR4	0x00000000
#elif SW5_BIT<8
#define SW5_EXTICR1	0x00000000
#define SW5_EXTICR2	(SW5_EXTI_PORT<<(SW5_BIT-4)*8)
#define SW5_EXTICR3	0x00000000
#define SW5_EXTICR4	0x00000000
#elif SW5_BIT<12
#define SW5_EXTICR1	0x00000000
#define SW5_EXTICR2	0x00000000
#define SW5_EXTICR3	(SW5_EXTI_PORT<<(SW5_BIT-8)*8)
#define SW5_EXTICR4	0x00000000
#else
#define SW5_EXTICR1	0x00000000
#define SW5_EXTICR2	0x00000000
#define SW5_EXTICR3	0x00000000
#define SW5_EXTICR4	(SW5_EXTI_PORT<<(SW5_BIT-12)*8)
#endif
#define SW5_EXTIMSK	(1<<SW5_BIT)
#else					//SW5を実装しないとき
#define SW5_EXTICR1	0x00000000
#define SW5_EXTICR2	0x00000000
#define SW5_EXTICR3	0x00000000
#define SW5_EXTICR4	0x00000000
#define SW5_EXTIMSK	0x00000000
#endif

//SW6の構成-------------------------------------
#ifdef SW6_BIT				//SW6を実装するとき
#ifdef SW6_TIMER
#define SW6_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW6_REAL
#define SW6_MODE 0x00
#define SW_REAL
#endif
#ifdef SW6_INV
#define SW6_POL 0x00
#else
#define SW6_POL SW_POL
#endif
	{SW6_GPIO,1<<SW6_BIT,SW6_MODE|SW6_POL},
#if SW6_BIT<4
#define SW6_EXTICR1	(SW6_EXTI_PORT<<SW6_BIT*8)
#define SW6_EXTICR2	0x00000000
#define SW6_EXTICR3	0x00000000
#define SW6_EXTICR4	0x00000000
#elif SW6_BIT<8
#define SW6_EXTICR1	0x00000000
#define SW6_EXTICR2	(SW6_EXTI_PORT<<(SW6_BIT-4)*8)
#define SW6_EXTICR3	0x00000000
#define SW6_EXTICR4	0x00000000
#elif SW6_BIT<12
#define SW6_EXTICR1	0x00000000
#define SW6_EXTICR2	0x00000000
#define SW6_EXTICR3	(SW6_EXTI_PORT<<(SW6_BIT-8)*8)
#define SW6_EXTICR4	0x00000000
#else
#define SW6_EXTICR1	0x00000000
#define SW6_EXTICR2	0x00000000
#define SW6_EXTICR3	0x00000000
#define SW6_EXTICR4	(SW6_EXTI_PORT<<(SW6_BIT-12)*8)
#endif
#define SW6_EXTIMSK	(1<<SW6_BIT)
#else					//SW6を実装しないとき
#define SW6_EXTICR1	0x00000000
#define SW6_EXTICR2	0x00000000
#define SW6_EXTICR3	0x00000000
#define SW6_EXTICR4	0x00000000
#define SW6_EXTIMSK	0x00000000
#endif

//SW7の構成-------------------------------------
#ifdef SW7_BIT				//SW7を実装するとき
#ifdef SW7_TIMER
#define SW7_MODE SW_MODE
#define SW_TIMER
#endif
#ifdef SW7_REAL
#define SW7_MODE 0x00
#define SW_REAL
#endif
#ifdef SW7_INV
#define SW7_POL 0x00
#else
#define SW7_POL SW_POL
#endif
	{SW7_GPIO,1<<SW7_BIT,SW7_MODE|SW7_POL},
#if SW7_BIT<4
#define SW7_EXTICR1	(SW7_EXTI_PORT<<SW7_BIT*8)
#define SW7_EXTICR2	0x00000000
#define SW7_EXTICR3	0x00000000
#define SW7_EXTICR4	0x00000000
#elif SW7_BIT<8
#define SW7_EXTICR1	0x00000000
#define SW7_EXTICR2	(SW7_EXTI_PORT<<(SW7_BIT-4)*8)
#define SW7_EXTICR3	0x00000000
#define SW7_EXTICR4	0x00000000
#elif SW7_BIT<12
#define SW7_EXTICR1	0x00000000
#define SW7_EXTICR2	0x00000000
#define SW7_EXTICR3	(SW7_EXTI_PORT<<(SW7_BIT-8)*8)
#define SW7_EXTICR4	0x00000000
#else
#define SW7_EXTICR1	0x00000000
#define SW7_EXTICR2	0x00000000
#define SW7_EXTICR3	0x00000000
#define SW7_EXTICR4	(SW7_EXTI_PORT<<(SW7_BIT-12)*8)
#endif
#define SW7_EXTIMSK	(1<<SW7_BIT)
#else					//SW7を実装しないとき
#define SW7_EXTICR1	0x00000000
#define SW7_EXTICR2	0x00000000
#define SW7_EXTICR3	0x00000000
#define SW7_EXTICR4	0x00000000
#define SW7_EXTIMSK	0x00000000
#endif
};

//EXTICR設定値
#define SW_EXTICR1	(SW0_EXTICR1|SW1_EXTICR1|SW2_EXTICR1|SW3_EXTICR1|\
			SW4_EXTICR1|SW5_EXTICR1|SW6_EXTICR1|SW7_EXTICR1)
#define SW_EXTICR2	(SW0_EXTICR2|SW1_EXTICR2|SW2_EXTICR2|SW3_EXTICR2|\
			SW4_EXTICR2|SW5_EXTICR2|SW6_EXTICR2|SW7_EXTICR2)
#define SW_EXTICR3	(SW0_EXTICR3|SW1_EXTICR3|SW2_EXTICR3|SW3_EXTICR3|\
			SW4_EXTICR3|SW5_EXTICR3|SW6_EXTICR1|SW7_EXTICR3)
#define SW_EXTICR4	(SW0_EXTICR4|SW1_EXTICR4|SW2_EXTICR4|SW3_EXTICR4|\
			SW4_EXTICR4|SW5_EXTICR4|SW6_EXTICR4|SW7_EXTICR4)
#define SW_EXTIMSK	(SW0_EXTIMSK|SW1_EXTIMSK|SW2_EXTIMSK|SW3_EXTIMSK|\
			SW4_EXTIMSK|SW5_EXTIMSK|SW6_EXTIMSK|SW7_EXTIMSK)

//SWの実装数
#define	SW_SU	(sizeof(sw_cnf)/sizeof(sw_cnf[0]))

#include "func_SW.c"				//SW評価ﾓｼﾞｭｰﾙを呼込む
#endif


#ifdef CVD_EN				//CVDを実装するとき
//==============================================
//CVD構成の定義
//==============================================
#define	CVD_MODE	0x80			//ﾓｰﾄﾞ設定ﾏｽｸ
static const struct CVD_CNF
{
	GPIO_TypeDef *gpio;			//GPIOｱﾄﾞﾚｽ
	unsigned short chsel;			//CHSELﾏｽｸ/ANIN番号
	unsigned char mode;			//b7:ﾓｰﾄﾞ(0=ﾘｱﾙﾓｰﾄﾞ､1=ﾀｲﾏｰﾓｰﾄﾞ)
						//b3-b0:ﾋﾞｯﾄ番号
}cvd_cnf[]=
{

//CVD0の構成-------------------------------------
#ifdef CVD0_BIT
#ifdef CVD0_TIMER
#define CVD0_MODE CVD_MODE
#define CVD_TIMER
#endif
#ifdef CVD0_REAL
#define CVD0_MODE 0x00
#define CVD_REAL
#endif
	{CVD0_GPIO,CVD0_CHSEL,CVD0_MODE|CVD0_BIT},
#endif

//CVD1の構成-------------------------------------
#ifdef CVD1_BIT
#ifdef CVD1_TIMER
#define CVD1_MODE CVD_MODE
#define CVD_TIMER
#endif
#ifdef CVD1_REAL
#define CVD1_MODE 0x00
#define CVD_REAL
#endif
	{CVD1_GPIO,CVD1_CHSEL,CVD1_MODE|CVD1_BIT},
#endif

//CVD2の構成-------------------------------------
#ifdef CVD2_BIT
#ifdef CVD2_TIMER
#define CVD2_MODE CVD_MODE
#define CVD_TIMER
#endif
#ifdef CVD2_REAL
#define CVD2_MODE 0x00
#define CVD_REAL
#endif
	{CVD2_GPIO,CVD2_CHSEL,CVD2_MODE|CVD2_BIT},
#endif

//CVD3の構成-------------------------------------
#ifdef CVD3_BIT
#ifdef CVD3_TIMER
#define CVD3_MODE CVD_MODE
#define CVD_TIMER
#endif
#ifdef CVD3_REAL
#define CVD3_MODE 0x00
#define CVD_REAL
#endif
	{CVD3_GPIO,CVD3_CHSEL,CVD3_MODE|CVD3_BIT},
#endif

//CVD4の構成-------------------------------------
#ifdef CVD4_BIT
#ifdef CVD4_TIMER
#define CVD4_MODE CVD_MODE
#define CVD_TIMER
#endif
#ifdef CVD4_REAL
#define CVD4_MODE 0x00
#define CVD_REAL
#endif
	{CVD4_GPIO,CVD4_CHSEL,CVD4_MODE|CVD4_BIT},
#endif

//CVD5の構成-------------------------------------
#ifdef CVD5_BIT
#ifdef CVD5_TIMER
#define CVD5_MODE CVD_MODE
#define CVD_TIMER
#endif
#ifdef CVD5_REAL
#define CVD5_MODE 0x00
#define CVD_REAL
#endif
	{CVD5_GPIO,CVD5_CHSEL,CVD5_MODE|CVD5_BIT},
#endif
};

#define	CVD_SU	(sizeof(cvd_cnf)/sizeof(cvd_cnf[0]))
						//CVDの実装数

#include "func_CVD.c"				//CVD評価ﾓｼﾞｭｰﾙを呼込む
#endif


//==============================================
//固有の作業域
//==============================================
#if defined(KYOKU_RAND)||defined(ONSEIN_RAND)||defined(ONSEII_RAND)||defined(ONSEIC_RAND)||defined(ONSEIS_RAND)	//どれかでﾗﾝﾀﾞﾑが必要なとき
static unsigned char rand_x;			//ﾗﾝﾀﾞﾏｲｽﾞの種
#endif
#if PART_N>0
static unsigned char kyoku;
#ifdef KYOKU_RAND
static unsigned char kyoku_rand_msk;
#endif
#endif
#if VOICE_N>0
static unsigned char onseiN;
#ifdef ONSEIN_RAND
static unsigned char onseiN_rand_msk;
#endif
#endif
#if VOICE_I>0
static unsigned char onseiI;
#ifdef ONSEII_RAND
static unsigned char onseiI_rand_msk;
#endif
#endif
#if VOICE_C>0
static unsigned char onseiC;
#ifdef ONSEIC_RAND
static unsigned char onseiC_rand_msk;
#endif
#endif
#if VOICE_S>0
static unsigned char onseiS;
#ifdef ONSEIS_RAND
static unsigned char onseiS_rand_msk;
#endif
#endif


//==============================================
//ｱﾌﾟﾘの初期設定
//==============================================
static void apl_init(void)
{

//DBG_C('\n');
//DBG_C('$');

	//LEDﾎﾟｰﾄ設定
#ifdef LED0_BIT				//LED0を実装するとき
	GPIO_OUT(LED0_GPIO,LED0_BIT);		//出力ﾓｰﾄﾞ
#endif
#ifdef LED1_BIT				//LED1を実装するとき
	GPIO_OUT(LED1_GPIO,LED1_BIT);		//出力ﾓｰﾄﾞ
#endif
#ifdef LED2_BIT				//LED2を実装するとき
	GPIO_OUT(LED2_GPIO,LED2_BIT);		//出力ﾓｰﾄﾞ
#endif
#ifdef LED3_BIT				//LED3を実装するとき
	GPIO_OUT(LED3_GPIO,LED3_BIT);		//出力ﾓｰﾄﾞ
#endif
#ifdef LED4_BIT				//LED4を実装するとき
	GPIO_OUT(LED4_GPIO,LED4_BIT);		//出力ﾓｰﾄﾞ
#endif
#ifdef LED5_BIT				//LED5を実装するとき
	GPIO_OUT(LED5_GPIO,LED5_BIT);		//出力ﾓｰﾄﾞ
#endif
#ifdef LED6_BIT				//LED6を実装するとき
	GPIO_OUT(LED6_GPIO,LED6_BIT);		//出力ﾓｰﾄﾞ
#endif

	//SWﾎﾟｰﾄ設定
//DBG_C('p');
#ifdef SW_EN				//SWを実装するとき
	RCC->APBENR2|=RCC_APBENR2_SYSCFGEN;
					//SYSCFGにｸﾛｯｸ供給
#ifdef SW0_BIT				//SW0を実装するとき
#ifdef SW0_INV				//負論理のとき
	GPIO_INPU(SW0_GPIO,SW0_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW0_GPIO,SW0_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW1_BIT				//SW1を実装するとき
#ifdef SW1_INV				//負論理のとき
	GPIO_INPU(SW1_GPIO,SW1_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW1_GPIO,SW1_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW2_BIT				//SW2を実装するとき
#ifdef SW2_INV				//負論理のとき
	GPIO_INPU(SW2_GPIO,SW2_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW2_GPIO,SW2_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW3_BIT				//SW3を実装するとき
#ifdef SW3_INV				//負論理のとき
	GPIO_INPU(SW3_GPIO,SW3_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW3_GPIO,SW3_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW4_BIT				//SW4を実装するとき
#ifdef SW4_INV				//負論理のとき
	GPIO_INPU(SW4_GPIO,SW4_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW4_GPIO,SW4_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW5_BIT				//SW5を実装するとき
#ifdef SW5_INV				//負論理のとき
	GPIO_INPU(SW5_GPIO,SW5_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW5_GPIO,SW5_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW6_BIT				//SW6を実装するとき
#ifdef SW6_INV				//負論理のとき
	GPIO_INPU(SW6_GPIO,SW6_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW6_GPIO,SW6_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#ifdef SW7_BIT				//SW7を実装するとき
#ifdef SW7_INV				//負論理のとき
	GPIO_INPU(SW7_GPIO,SW7_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙｱｯﾌﾟする
#else					//正論理のとき
	GPIO_INPD(SW7_GPIO,SW7_BIT);		//入力ﾓｰﾄﾞﾌﾟﾙﾀﾞｳﾝする
#endif
#endif
#endif

#ifdef SLEEP_EN				//Sleepを実装するとき
	//Wakeup設定
#if defined(CdS_EN)||defined(CVD_EN)||defined(SW_PLNG)
					//CdSかCVDを実装するとき､
					//　SWをﾎﾟｰﾘﾝｸﾞするときは
					//　LPTIM割込みでWakeupする

	//LPTIM設定
	RCC->CSR|=RCC_CSR_LSION;		//LSIｵﾝ
	while(!(RCC->CSR&RCC_CSR_LSIRDY)){};	//LSIﾚﾃﾞｨを待つ
	RCC->CCIPR|=RCC_CCIPR_LPTIMSEL_0;	//LPTIMｸﾛｯｸはLSI
	RCC->APBENR1|=RCC_APBENR1_LPTIMEN;	//LPTIMにｸﾛｯｸ供給
	LPTIM->IER|=LPTIM_IER_ARRMIE;		//LPTIM割込み許可
	LPTIM->CR|=LPTIM_CR_ENABLE;		//LPTIM有効
	LPTIM->ARR=32*32;			//周期は32ms
//DBG_L(LPTIM->ARR);
	NVIC->ISER[0]=(1<<LPTIM1_IRQn);		//LPTIM割込み許可

#else					//CdSもCVDも実装しないとき､
					//　SWをﾎﾟｰﾘﾝｸﾞしないときは
					//　EXTI0～15(SW)割込みでWakeupする

//DBG_C('s');
#ifdef SW_EN				//SWを実装するとき

	//EXTI設定
#if SW_EXTICR1!=0x00000000
	EXTI->EXTICR[0]=SW_EXTICR1;
#endif
#if SW_EXTICR2!=0x00000000
	EXTI->EXTICR[1]=SW_EXTICR2;
#endif
#if SW_EXTICR3!=0x00000000
	EXTI->EXTICR[2]=SW_EXTICR3;
#endif
#if SW_EXTICR4!=0x00000000
	EXTI->EXTICR[3]=SW_EXTICR4;
#endif
	EXTI->RTSR=EXTI->FTSR=SW_EXTIMSK;

//DBG_C('\n');
//DBG_L(EXTI->FTSR);
//DBG_C('-');
//DBG_L(EXTI->RTSR);
	NVIC->ISER[0]=
		(1<<EXTI0_1_IRQn)|		//EXTI0_1割込み許可
		(1<<EXTI2_3_IRQn)|		//EXTI2_3割込み許可
		(1<<EXTI4_15_IRQn);		//EXTI4_15割込み許可
//DBG_C('-');
//DBG_L(NVIC->ISER[0]);
#endif
#endif
#endif
}


#ifdef	SLEEP_EN			//Sleep機能を実装するとき
#if defined(CdS_EN)||defined(CVD_EN)||defined(SW_PLNG)
					//CdSかCVDを実装するとき､
					//　SWをﾎﾟｰﾘﾝｸﾞするとき
//==============================================
//LPTIM割込み処理
//==============================================
void LPTIM1_IRQHandler(void)
{

//DBS_H;
	LPTIM->ICR|=LPTIM_ICR_ARRMCF;
//DBS_L;
}


#else					//CdSもCVDも実装しないとき､
					//　SWをﾎﾟｰﾘﾝｸﾞしないとき
//==============================================
//EXTI割込みﾊﾝﾄﾞﾗ
//==============================================
void EXTI0_1_IRQHandler(void)
{

	EXTI->PR=0x00000003;			//EXTI0-1割込みﾌﾗｸﾞをｸﾘｱする
}

void EXTI2_3_IRQHandler(void)
{

	EXTI->PR=0x0000000c;			//EXTI2-3割込みﾌﾗｸﾞをｸﾘｱする
}

void EXTI4_15_IRQHandler(void)
{

	EXTI->PR=0x0000fff0;			//EXTI4-115割込みﾌﾗｸﾞをｸﾘｱする
}
#endif


//==============================================
//Sleep処理
//==============================================
static void apl_sleep(void)
{
#if defined(CdS_EN)||defined(CVD_EN)||defined(SW_PLNG)
					//CdSかCVDを実装するとき､
					//　SWをﾎﾟｰﾘﾝｸﾞするとき
	unsigned char n;
#endif

//DBG_C('\n');
//DBG_C('<');

	//LED消灯
#ifdef LED0_BIT				//LED0を実装するとき
	GPIO_L(LED0_GPIO,LED0_BIT);		//消灯する
#endif
#ifdef LED1_BIT				//LED1を実装するとき
	GPIO_L(LED1_GPIO,LED1_BIT);		//消灯する
#endif
#ifdef LED2_BIT				//LED2を実装するとき
	GPIO_L(LED2_GPIO,LED2_BIT);		//消灯する
#endif
#ifdef LED3_BIT				//LED3を実装するとき
	GPIO_L(LED3_GPIO,LED3_BIT);		//消灯する
#endif
#ifdef LED4_BIT				//LED4を実装するとき
	GPIO_L(LED4_GPIO,LED4_BIT);		//消灯する
#endif
#ifdef LED5_BIT				//LED5を実装するとき
	GPIO_L(LED5,GPIO,LED5_BIT);		//消灯する
#endif
#ifdef LED6_BIT				//LED6を実装するとき
	GPIO_L(LED6_GPIO,LED6_BIT);		//消灯する
#endif

#if VOICE_S>0				//音声S再生を実装するとき
	//W25をﾊﾟﾜｰﾀﾞｳﾝ
//DBG_C('a');
	W25_PWR_DOWN();				//W25をﾊﾟﾜｰﾀﾞｳﾝする
#endif

	//SPIをﾘｾｯﾄ
#if VOICE_C+VOICE_S>0			//SPIを使うとき
//DBG_C('b');
	spi_reset();				//SPIﾎﾟｰﾄをﾘｾｯﾄする
#endif

	//PWMを停止
//DBG_C('c');
	dev_pwm_stop();				//PWMを停止する

	//Sleep処理
#if defined(CdS_EN)||defined(CVD_EN)||defined(SW_PLNG)
					//CdSかCVDを実装するとき､
					//　SWをﾎﾟｰﾘﾝｸﾞするときは
					//　LPTIM割込みでWakeupする
	for(;;)
	{
//DBG_C('d');
		//SLEEPDEEPﾓｰﾄﾞへ移行
//DBG_SYNC();
//DBS_H;
		//AWU設定
		LPTIM->CR|=LPTIM_CR_SNGSTRT;	//ｶｳﾝﾄ開始

		//低電力設定
		PWR->CR1|=PWR_CR1_LPR|PWR_CR1_VOS|PWR_CR1_MRRDY_TIME_Msk;
						//ﾚｷﾞｭﾚｰﾀを低電力､VDD=1.0V､MRRDY_TIMEは5us
		RCC->CFGR=0x00000000;		//SYSCLKはHSI
DBS_H;
		__WFI();			//SLEEPDEEPﾓｰﾄﾞへ移行
		SystemInit();			//ｼｽﾃﾑｸﾛｯｸを再設定する
//DBS_L;
		wait_us(80);
//DBG_C('e');

#ifdef SW_EN				//SWを実装するとき
		//SWを評価する
//DBG_C('f');
		for(n=0;n<SW_SU;n++)
		{
			if(sw_read(n,1)) break;	//操作を検知したら抜ける
		}
		if(n<SW_SU) break;
#endif

#ifdef CdS_EN				//CdSを実装するとき
		//CdSを評価する
//DBG_C('g');
		if(cds_read(1)) break;		//操作を検知したら抜ける
#endif

#ifdef CVD_EN				//CVDを実装するとき
		//CVDを評価する
//DBG_C('h');
		for(n=0;n<CVD_SU;n++)
		{
			if(cvd_read(n,1)) break;//操作を検知したら抜ける
		}
		if(n<CVD_SU) break;
#endif
	}

#else					//CdSもCVDも実装しないとき､
					//　SWをﾎﾟｰﾘﾝｸﾞしないときは
					//　EXTI0～15(SW)割込みでWakeupする
//DBG_C('i');
//DBG_SYNC();

	//STOPﾓｰﾄﾞへ移行
	EXTI->IMR=SW_EXTIMSK;			//EXTI割込み許可

	//低電力設定
	PWR->CR1|=PWR_CR1_LPR|PWR_CR1_VOS|PWR_CR1_MRRDY_TIME_Msk;
						//ﾚｷﾞｭﾚｰﾀを低電力､VDD=1.0V､MRRDY_TIMEは5us
	RCC->CFGR=0x00000000;			//SYSCLKはHSI
	__WFI();				//STOPﾓｰﾄﾞへ移行
	EXTI->IMR=0x00000000;			//EXTI割込み禁止
	SystemInit();				//ｼｽﾃﾑｸﾛｯｸを再設定する
//DBG_C('j');
#endif

	//PWMを再稼働
//DBG_C('k');
	dev_pwm_start();			//PWMを開始する

	//SPIをｾｯﾄ
#if VOICE_C+VOICE_S>0			//SPIを使うとき
//DBG_C('l');
	spi_set();				//SPIﾎﾟｰﾄをｾｯﾄする
#endif

	//W25をﾊﾟﾜｰｱｯﾌﾟ
#if VOICE_S>0				//音声S再生を実装するとき
//DBG_C('n');
	W25_PWR_UP();				//W25をﾊﾟﾜｰｱｯﾌﾟする
#endif
//DBG_C('>');
}
#endif


//==============================================
//固有の処理(ｺｰﾙﾊﾞｯｸ関数)
//==============================================

//定数宣言
#define	ONSEI_irassyai	1
#define	ONSEI_okaikei	2
#define	ONSEI_hawaii	3
#define	ONSEI_NEDAN	4
#define	NEDAN_SU	9
#define	LED_TMR		128

static void CB_KOYUU(void)
{
	static unsigned char nedan;
	static unsigned char led_tmr;
#ifdef SLEEP_EN				//Sleep機能を実装するとき
	static unsigned short sleep_tmr=0;	//Sleepﾀｲﾏｰ
#endif
	unsigned char res,cnt,n;
#if PART_N>0				//ｵﾙｺﾞｰﾙ演奏を実装するとき
	struct SONG_IDX *p;
#endif

//DBG_C('\n');
//DBG_S(voiceS[0].no);

	//稼働ﾁｪｯｸ
#ifdef SLEEP_EN				//Sleep機能を実装するとき
//DBG_C('e');
	res=0;					//仮に非稼働にしておく
#if PART_N>0				//ｵﾙｺﾞｰﾙ演奏を実装するとき
	res|=song.no;				//稼働しているときは稼働中の設定
#endif
#if VOICE_N>0				//音声N再生を実装するとき
	res|=voiceN[0].no;			//稼働しているときは稼働中の設定
#endif
#if VOICE_I>0				//音声I再生を実装するとき
	res|=voiceI.no;				//稼働しているときは稼働中の設定
#endif
#if VOICE_C>0				//音声C再生を実装するとき
	res|=voiceC.no;				//稼働しているときは稼働中の設定
#endif
#if VOICE_S>0				//音声S再生を実装するとき
	res|=voiceS[0].no;			//稼働しているときは稼働中の設定
#endif
//DBG_B(res);
	if(res)					//稼働しているときは
	{
//DBG_C('o');

		//LED点滅
		if(voiceS[0].no)
		{
			if(++led_tmr>=LED_TMR/KOYUU_PR) led_tmr=0;
//DBG_B(led_tmr);
			if(led_tmr<LED_TMR/KOYUU_PR/2) GPIO_H(LED0_GPIO,LED0_BIT);
			else GPIO_L(LED0_GPIO,LED0_BIT);
		}
		sleep_tmr=0;			//　Sleep時限をｸﾘｱする
	}
	else					//稼働していないときは
	{
//DBG_C('x');
		//LED消灯
		GPIO_L(LED0_GPIO,LED0_BIT);
//DBG_S(sleep_tmr);
		if(++sleep_tmr>SLEEP_TMR/KOYUU_PR)
						//　Sleep時限を超えたら
		{
			apl_sleep();		//　Sleepする
			sleep_tmr=0;		//　Sleep時限をｸﾘｱする
		}
	}
#endif

#ifdef SW_EN				//SWを実装するとき
	//SW0(引出し)操作
//DBG_C('h');
	res=sw_read(0,0);
//DBG_B(res);
	if(res==1) VOICES_SEL(0,ONSEI_okaikei);
	else if(res==2) VOICES_SEL(0,ONSEI_irassyai);

	//SW1(ｽｷｬﾅ)操作
//DBG_C('s');
	res=sw_read(1,0);
//DBG_B(res);
	if(res==1) VOICES_SEL(0,ONSEI_NEDAN+nedan);
	else if(res==2) VOICES_SEL(0,ONSEI_hawaii);
#endif

#ifdef CVD_EN				//CVDを実装するとき
	//CVD0(ﾀｯﾁ)操作
//DBG_C('s');
	res=cvd_read(0,0);
//DBG_B(res);
	if(res==1) VOICES_SEL(0,ONSEI_NEDAN+nedan);
	else if(res==2) VOICES_SEL(0,ONSEI_hawaii);
#endif

	//値段のﾗﾝﾀﾞﾏｲｽﾞ
//DBG_C('n');
	if(++nedan>=NEDAN_SU) nedan=0;
//DBG_B(nedan);
}


#if	PART_N>0			//ｵﾙｺﾞｰﾙ演奏を実装するとき
//==============================================
//演奏終了時の処理(ｺｰﾙﾊﾞｯｸ関数)
//==============================================
static void CB_SONG_END(void)
{
}
#endif


#if	VOICE_N>0			//音声N再生を実装するとき
//==============================================
//音声0再生終了時の処理(ｺｰﾙﾊﾞｯｸ関数)
//==============================================
static void CB_VOICEN_END(
	unsigned char ch)			//音声Nのch番号
{
}
#endif


#if	VOICE_I>0			//音声I再生を実装するとき
//==============================================
//音声I再生終了時の処理(ｺｰﾙﾊﾞｯｸ関数)
//==============================================
static void CB_VOICEI_END(void)
{
}
#endif


#if	VOICE_C>0			//音声C再生を実装するとき
//==============================================
//音声C再生終了時の処理(ｺｰﾙﾊﾞｯｸ関数)
//==============================================
static void CB_VOICEC_END(void)
{
}
#endif


#if	VOICE_S>0			//音声S再生を実装するとき
//==============================================
//音声S再生終了時の処理(ｺｰﾙﾊﾞｯｸ関数)
//==============================================
static void CB_VOICES_END(
	unsigned char ch)			//音声Sのch番号
{
}
#endif
