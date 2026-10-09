//#define	SHDBS		//ﾃﾞﾊﾞｸﾞ信号を出力するときに宣言する
//#define	SHDBG		//ﾃﾞﾊﾞｸﾞ情報を出力するときに宣言する
//#define	SHBPS	115200	//ﾃﾞﾊﾞｸﾞ情報のﾎﾞｰﾚｰﾄを宣言する(ﾃﾞﾌｫﾙﾄ値は38400bps)
//#define	SHDBG_SOFT	//ﾃﾞﾊﾞｸﾞ情報のUARTをｿﾌﾄ実装するときに宣言する		

#define	SHSPI3		//3線SPIのときに宣言する
#define	SLEEP_EN	//Sleep機能を実装するときに宣言する
#define	SW_EN		//SWを実装するときに宣言する
//#define	SW_PLNG		//SWをｲﾍﾞﾝﾄではなく､ﾎﾟｰﾘﾝｸﾞするときに宣言する
#define	CVD_EN		//CVDを実装するときに宣言する

//ここでCVD評価の閾値をｶｽﾀﾏｲｽﾞできる(ToyDr.わたなべ)
#define	CVD_THR1	5		//　閾値1を宣言する[既定値:20]
#define	CVD_THR2	10		//　閾値2を宣言する[既定値:40]
#define	CVD_INC		1		//　増分値を宣言する[既定値：4]

/*
PUYA32電子ｵﾙｺﾞｰﾙ演奏+音声再生ver1_4
これは根のｿｰｽｺｰﾄﾞ

・ﾀｰｹﾞｯﾄはPY32F002A_16ﾋﾟﾝ(内部48MHzｸﾛｯｸ)

｢ｷﾃｨちゃん たのしいおかいものｽｰﾊﾟｰﾏｰｹｯﾄ｣の故障基板を､PUYA電子ｵﾙｺﾞｰﾙで換装する
似たような音声を再現するﾌｧｰﾑを､今回のお客さま専用として作成(2026/1/7 ToyDr.わたなべ)

【動作仕様】
このﾓﾃﾞﾙでは､引き出し奥のﾏｲｸﾛSW0のﾉｰﾏﾙｸﾛｰｽﾞ接点をﾘｱﾙﾓｰﾄﾞで､
ﾚｼﾞの商品ｽｷｬﾅは､ﾀｸﾄSW1(及びｵﾌﾟｼｮﾝでCVD0も)を､ﾀｲﾏｰﾓｰﾄﾞで実装する
16ﾋﾟﾝﾃﾞﾊﾞｲｽで､SPIﾌﾗｯｼｭの音声ﾃﾞｰﾀを3線SPIで､ﾌﾞﾚｰｷ出力する

SW0は､､ｵﾝからｵﾌ判定で 開店ｱﾅｳﾝｽを再生､ｵﾌからｵﾝ判定では 会計ｱﾅｳﾝｽを再生する
音声再生中のSW0操作では、それぞれに対応する音声を再生開始する
このSW0の特徴は､通常は押下状態で接点ｵｰﾌﾟﾝが続き､接点ｸﾛｰｽﾞ時も音声再生すること

SW1(及びｵﾌﾟｼｮﾝでCVD0)は､短ｵﾝで 値段読み上げ音声をﾗﾝﾀﾞﾑ再生､長ｵﾝで 景品当選ｱﾅｳﾝｽを再生する

LEDは1個を実装し､音声再生中は約7.8Hzで点滅する

単3電池2本で駆動し､電源ｽｲｯﾁはないため､稼働していないときは省電力でｽﾘｰﾌﾟする

音源のﾊﾞｯｸｱｯﾌﾟがないため、別の中古品から録音したり音声合成ｿﾌﾄで生成する
音声ﾃﾞｰﾀはSPIﾌﾗｯｼｭに格納しておき､8ksps_8bitで再生する

このｺｰﾄﾞは｢PUYA電子ｵﾙｺﾞｰﾙ+音声再生｣を､おもちゃ修理に応用するための限定版であり､
無用の共通化部分を含んでいる｡


//==============================================
//SPIﾌﾗｯｼｭﾒﾓﾘのﾋﾟﾝ接
//==============================================
W25Qのﾋﾟﾝ接(標準SPIﾓｰﾄﾞ)
1:CS(2線SPIでは10k*220pの時定数回路を介してCLKに繋ぐ)
2:DO(2線SPI･3線SPIではDIに繋ぐ)
3:WP(GNDに接続)
4:GND
5:DI
6:CLK
7:HOLD(Vccに接続)
8:Vcc


//==============================================
//PY32のﾋﾟﾝ接
//==============================================
PY32F002A(16ﾋﾟﾝ)のﾎﾟｰﾄの割当て
1:(PA7)/(ADC_IN7)CVD0
2:(PB0)
3:(PB1)/(TIM1_CH3N)ﾌﾞﾚｰｷ逆相出力
4:Vcc
5:(PA9)/(TIM1_CH2)正相出力
6:(PA13-SWD)ﾃﾞﾊﾞｸﾞ信号
7:(PA14-SWC)ﾃﾞﾊﾞｸﾞ情報/(USART1_TX)ﾃﾞﾊﾞｸﾞ情報
8:(PF2-NRST)
9:(PF0-OSCIN)
10:(PF1-OSCOUT)LED0
11:(PA0)SW0
12:(PA1)BOOT0代替/(SPI1_MOSI)MOSI(M25QのDI･DOに繋ぐ)
13:Vss
14:(PA2)/(SPI1_SCK)SCK(M25QのCLKに繋ぐ)
15:(PA3)SW1
16:(PA6)SS(M25QのCSに繋ぐ)
*/


//==============================================
//ﾍｯﾀﾞﾌｧｲﾙの呼込み
//==============================================
#include "py32f0xx.h"				//ｼｽﾃﾑのﾍｯﾀﾞﾌｧｲﾙ
#include "orgel_cnf.h"				//構成情報
#include "../orgel.h"				//ｱﾌﾟﾘのﾍｯﾀﾞﾌｧｲﾙ


//==============================================
//構成情報(ｱﾌﾟﾘｹｰｼｮﾝとﾀｰｹﾞｯﾄﾃﾞﾊﾞｲｽに関わるもの)
//==============================================
//ｼｽﾃﾑｸﾛｯｸ
#define	SYS_CLK		48			//ｼｽﾃﾑｸﾛｯｸ周波数[MHz]

//ﾃﾞﾊﾞｸﾞ信号のﾎﾟｰﾄ定義
#define	DBS_GPIO	GPIOA			//ﾃﾞﾊﾞｸﾞ信号のﾎﾟｰﾄ
#define	DBS_BIT		13			//ﾃﾞﾊﾞｸﾞ信号のﾋﾞｯﾄ

//ﾃﾞﾊﾞｸﾞ情報のﾎﾟｰﾄ定義
#define	DBG_GPIO	GPIOA			//ﾃﾞﾊﾞｸﾞ情報のﾎﾟｰﾄ
#define	DBG_BIT		14			//ﾃﾞﾊﾞｸﾞ情報のﾋﾞｯﾄ
#define	DBG_AF		1			//UARTの交代機能番号

//PWMのﾎﾟｰﾄ定義
#define	PWM_F_GPIO	GPIOA			//PWM正相のﾎﾟｰﾄ
#define	PWM_F_BIT	9			//PWM正相のﾋﾞｯﾄ
#define	PWM_F_AF	2			//PWM正相の交代機能番号
#define	PWM_R_GPIO	GPIOB			//PWM逆相のﾎﾟｰﾄ
#define	PWM_R_BIT	1			//PWM逆相のﾋﾞｯﾄ
#define	PWM_R_AF	2			//PWM逆相の交代機能番号
#define	PWM_C_GPIO	GPIOB			//PWM相補のﾎﾟｰﾄ
#define	PWM_C_BIT	0			//PWM相補のﾋﾞｯﾄ
#define	PWM_C_AF	2			//PWM相補の交代機能番号

//I2Cのﾎﾟｰﾄ定義
#define I2C_SCL_GPIO	GPIOA			//SCLのﾎﾟｰﾄ
#define I2C_SCL_BIT	3			//SCLのﾋﾞｯﾄ
#define	I2C_SCL_AF	12			//SCLの交代機能番号
#define I2C_SDA_GPIO	GPIOA			//SDAのﾎﾟｰﾄ
#define I2C_SDA_BIT	7			//SDAのﾋﾞｯﾄ
#define	I2C_SDA_AF	12			//SDAの交代機能番号

//SPIのﾎﾟｰﾄ定義
#define SPI_SCK_GPIO	GPIOA			//SCKのﾎﾟｰﾄ
#define SPI_SCK_BIT	2			//SCKのﾋﾞｯﾄ
#define	SPI_SCK_AF	10			//SCKの交代機能番号
#define SPI_MOSI_GPIO	GPIOA			//MOSIのﾎﾟｰﾄ
#define SPI_MOSI_BIT	1			//MOSIのﾋﾞｯﾄ
#define	SPI_MOSI_AF	10			//MOSIの交代機能番号
#ifdef SHSPI2				//2線SPIのとき
#define	SPI_SS_TIME	5			//SSﾈｹﾞｰﾄ待ち時間[us]
#define SPI_SS_GPIO	SPI_SCK_GPIO		//SSのﾎﾟｰﾄ
#define SPI_SS_BIT	SPI_SCK_BIT		//SSのﾋﾞｯﾄ
#else					//3線SPIまたは4線SPIのとき
#define SPI_SS_GPIO	GPIOA			//SSのﾎﾟｰﾄ
#define SPI_SS_BIT	6			//SSのﾋﾞｯﾄ
#endif
#if defined(SHSPI2)||defined(SHSPI3)	//2線SPIまたは3線SPIのとき
#define	SPI_SOFT				//SPIをｿﾌﾄ実装する
#define SPI_MISO_GPIO	SPI_MOSI_GPIO		//MISOのﾎﾟｰﾄ
#define SPI_MISO_BIT	SPI_MOSI_BIT		//MISOのﾋﾞｯﾄ
#else					//4線SPIのとき
#define SPI_MISO_GPIO	GPIOA			//MISOのﾎﾟｰﾄ
#define SPI_MISO_BIT	0			//MISOのﾋﾞｯﾄ
#define	SPI_MISO_AF	10			//MISOの交代機能番号
#endif

//SPIのﾌﾟﾙｱｯﾌﾟ/ﾀﾞｳﾝ定義
#define	SPI_SCK_PU				//SPI_SCKをﾌﾟﾙｱｯﾌﾟする
//#define	SPI_SCK_PD			//SPI_SCKをﾌﾟﾙﾀﾞｳﾝする
#define	SPI_MOSI_PU				//SPI_MOSIをﾌﾟﾙｱｯﾌﾟする
//#define	SPI_MOSI_PD			//SPI_MOSIをﾌﾟﾙﾀﾞｳﾝする
#define	SPI_MISO_PU				//SPI_MISOをﾌﾟﾙｱｯﾌﾟする
//#define	SPI_MISO_PD			//SPI_MISOをﾌﾟﾙﾀﾞｳﾝする

//SW0のﾎﾟｰﾄ定義	(Dr.W)
#define	SW0_GPIO	GPIOA			//引き出し奥のﾏｲｸﾛSW0のﾎﾟｰﾄ
#define	SW0_EXTI_PORT	0			//SW0のEXTIﾎﾟｰﾄ(0=PA､1=PB､2=PF)
#define	SW0_BIT		0			//SW0のﾋﾞｯﾄ
#define	SW0_INV					//SW0入力は負論理
					//以下のﾀｲﾏｰﾓｰﾄﾞとﾘｱﾙﾓｰﾄﾞは択一
//#define SW0_TIMER				//SW0はﾀｲﾏｰﾓｰﾄﾞ
#define	SW0_REAL			//SW0はﾘｱﾙﾓｰﾄﾞ

//SW1のﾎﾟｰﾄ定義	(Dr.W)
#define	SW1_GPIO	GPIOA			//商品ｽｷｬﾅのﾀｸﾄSW1のﾎﾟｰﾄ
#define	SW1_EXTI_PORT	0			//SW1のEXTIﾎﾟｰﾄ(0=PA､1=PB､2=PF)
#define	SW1_BIT		3			//SW1のﾋﾞｯﾄ
#define	SW1_INV					//SW1入力は負論理
					//以下のﾀｲﾏｰﾓｰﾄﾞとﾘｱﾙﾓｰﾄﾞは択一
#define SW1_TIMER				//SW1はﾀｲﾏｰﾓｰﾄﾞ
//#define	SW1_REAL			//SW1はﾘｱﾙﾓｰﾄﾞ

//CVD0のﾎﾟｰﾄ定義
#define	CVD0_GPIO	GPIOA			//商品ｽｷｬﾅのｾﾝｻｰCVD0のﾎﾟｰﾄ
#define	CVD0_BIT	7			//CVD0のﾋﾞｯﾄ
#define	CVD0_CHSEL	0x0080			//CVD0のADCCHSEL
					//以下のﾀｲﾏｰﾓｰﾄﾞとﾘｱﾙﾓｰﾄﾞは択一
#define CVD0_TIMER				//CVD0はﾀｲﾏｰﾓｰﾄﾞ
//#define	CVD0_REAL			//CVD0はﾘｱﾙﾓｰﾄﾞ

//LEDのﾎﾟｰﾄ定義	(Dr.W)
#define	LED0_GPIO	GPIOF		//LED0のﾎﾟｰﾄ
#define	LED0_BIT	1		//LED0のﾋﾞｯﾄ




#if	VOICE_S>0
//==============================================
//音声ﾃﾞｰﾀ(SPIﾌﾗｯｼｭ)のｲﾝﾃﾞｯｸｽ
//==============================================
static const struct VOICES_HDR voiceS_idx[]=
{

	//｢ｷﾃｨちゃんｽｰﾊﾟｰﾏｰｹｯﾄ｣の音声ﾃﾞｰﾀ(voice_KITTYsuper\W25Q.hex)を使う (Dr.W)
	vos_mac(0x000000,0x005d88,8000)	//1:irassyai.wav
	vos_mac(0x005d88,0x010788,8000)	//2:okaikei.wav
	vos_mac(0x016510,0x00cf5c,8000)	//3:hawaii.wav
	vos_mac(0x02346c,0x003ea0,8000)	//4:50yen.wav
	vos_mac(0x02730c,0x00ed94,8000)	//5:100manyen.wav
	vos_mac(0x0360a0,0x004100,8000)	//6:100yen.wav
	vos_mac(0x03a1a0,0x004e84,8000)	//7:250yen.wav
	vos_mac(0x03f024,0x00748c,8000)	//8:300hangaku.wav
	vos_mac(0x0464b0,0x004368,8000)	//9:300yen.wav
	vos_mac(0x04a818,0x004568,8000)	//10:400yen.wav
	vos_mac(0x04ed80,0x004500,8000)	//11:500yen.wav
	vos_mac(0x053280,0x004468,8000)	//12:700yen.wav
};
#define VOICES_SU	(sizeof(voiceS_idx)/sizeof(voiceS_idx[0]))
#endif


//==============================================
//共通ｺｰﾄﾞの呼込み
//==============================================
#include "../dev_F002A_16.c"			//F002A_16ﾋﾟﾝﾃﾞﾊﾞｲｽｺｰﾄﾞ
#include "../apl_SW-KittyCashier.c"		//ｷﾃｨｷｬｯｼｬｰ操作ｱﾌﾟﾘｹｰｼｮﾝ
