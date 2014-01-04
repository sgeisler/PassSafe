/*
 * Copyright (c) 2011-2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.0
import bb.system 1.0

NavigationPane {
    id: nav
    Page {
        
        actions: [
            ActionItem {
                title: qsTr ("New Account")
                imageSource: "asset:///img/ic_add_entry.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                
                onTriggered: {
                    addAcc.show()                   
                }
            },
            ActionItem {
                title: qsTr ("Logout")
                imageSource: "asset:///img/ic_lock.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                
                onTriggered: {
                    accListModel.setPassword("")
                    accListDataModel.clear()
                    prompt.show()

                }
            }
        ]
        
        
        
        
        Container {
            layout: DockLayout {

            }
            ImageView {
                id: bgimg
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                imageSource: "asset:///bg.jpg"
                scalingMethod: ScalingMethod.AspectFill
            }
            ListView {
                id: accLst
                dataModel: ArrayDataModel {
                    id: accListDataModel

                }
                onTriggered: {
                    var chosenItem = dataModel.data(indexPath);
                    var contentpage = itemPageDefinition.createObject();

                    contentpage.itemPageTitle = accListModel.getAccountAt(indexPath)
                    contentpage.pass = accListModel.getPasswordAt(indexPath)
                    contentpage.i = indexPath[0]
                    nav.push(contentpage);
                }
                onCreationCompleted: {
                    prompt.show()
                }
                
                function reload()
                {
                    accListDataModel.clear()
                    var accNum = accListModel.getSize()
                    for (var i = 0; i < accNum; i ++) {
                        accListDataModel.append(accListModel.getAccountAt(i))
                    }
                }
                

            }
        }

    }
    attachedObjects: [
        ComponentDefinition {
            id: itemPageDefinition
            source: "ItemPage.qml"
        },
        ComponentDefinition {
            id: editPageDefinition
            source: "EditPage.qml"
        },
        SystemPrompt {
            id: prompt
            title: qsTr("Input Password")
            modality: SystemUiModality.Application
            inputField.inputMode: SystemUiInputMode.Password
            confirmButton.label: qsTr("Okay")
            confirmButton.enabled: true
            cancelButton.label: qsTr("Cancel")
            cancelButton.enabled: false
            onFinished: {
                if (result == SystemUiResult.ConfirmButtonSelection) {
                    accListModel.setPassword(prompt.inputFieldTextEntry())
                    accLst.reload()
                } else if (result == SystemUiResult.CancelButtonSelection) {
                    prompt.show()
                }
            }
            returnKeyAction: SystemUiReturnKeyAction.Submit

        },
        SystemPrompt {
            id: addAcc
            title: qsTr("Add Account")
            modality: SystemUiModality.Application
            inputField.inputMode: SystemUiInputMode.Email
            confirmButton.label: qsTr("Add Account")
            confirmButton.enabled: true
            cancelButton.label: qsTr("Cancel")
            cancelButton.enabled: true
            onFinished: {
                if (result == SystemUiResult.ConfirmButtonSelection) {
                    accListModel.addAccount(addAcc.inputFieldTextEntry(), 1, 28)
                    accLst.reload()
                }
            }
            returnKeyAction: SystemUiReturnKeyAction.Submit

        }
    ]
    onPopTransitionEnded: {
        page.destroy();
    }

}
