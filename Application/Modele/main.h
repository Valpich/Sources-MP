/**
 ******************************************************************************
 * @file    OV9655_Camera/inc/main.h
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    18-April-2011
 * @brief   Header for main.c module
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; Portions COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */
/**
 ******************************************************************************
 * <h2><center>&copy; Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.</center></h2>
 * @file    main.h
 * @author  CMP Team
 * @version V1.0.0
 * @date    28-December-2012
 * @brief   Header for main.c module
 *          Modified to support the STM32F4DISCOVERY, STM32F4DIS-BB, STM32F4DIS-CAM
 *          and STM32F4DIS-LCD modules.
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, Embest SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
 * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 ******************************************************************************
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4_uart.h"
#include "stm32f4_sys.h"
#include "appli.h"
#include "macro_types.h"
#include "stm32f4_timer.h"
#include "../../demo_touchscreen.h"
#include "../Vue/Menu_Principal_GUI.h"
#include "../../MAIL/Vue/Menu_MAIL_GUI.h"
#include "../../MAIL/Vue/Saisie_message_maj_GUI.h"
#include "../../MAIL/Vue/Saisie_message_min_GUI.h"
#include "../../MAIL/Vue/Saisie_message_chiffre_GUI.h"
#include "../../1010/Vue/Jeu_1010_GUI.h"
#include "../../1010/Jeu_1010.h"
#include "../../TicTacToe/Vue/Jeu_TicTacToe_GUI.h"
#include "../../MAIL/controleur/controleur_MAIL.h"
#include "../controleur/controleur_appli.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

int main(void);

void tache_principale();


#endif /* __MAIN_H */

/*********** Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.*****END OF FILE****/
